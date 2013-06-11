%{
#include "../MssqlDriver.h"
#include "../MssqlScanner.h"
#include "../SqlVariable.h"

using namespace std;
using namespace SyteLine::Technique::Code;
%}

%option c++
%option prefix = "CMssqlScanner"
%option debug
%option noyywrap
%option yylineno
%option outfile = "MssqlScanner.flex.out"
%option case-insensitive

%x M_PROCEDURE_DECLARATION
%x M_PROCEDURE_DECLARATION_END
%x M_FUNCTION_DECLARATION

%x M_DECLARE_VARIABLE

%x M_PROCEDURE
%x M_CALLED_PROCEDURE_ARGUMENT

RKeyword "ADD"|"EXISTS"|"PRECISION"|"ALL"|"EXIT"|"PRIMARY"|"ALTER"|"EXTERNAL"|"PRINT"|"AND"|"FETCH"|"PROC"|"ANY"|"FILE"|"PROCEDURE"|"AS"|"FILLFACTOR"|"PUBLIC"|"ASC"|"FOR"|"RAISERROR"|"AUTHORIZATION"|"FOREIGN"|"READ"|"BACKUP"|"FREETEXT"|"READTEXT"|"BEGIN"|"FREETEXTTABLE"|"RECONFIGURE"|"BETWEEN"|"FROM"|"REFERENCES"|"BREAK"|"FULL"|"REPLICATION"|"BROWSE"|"FUNCTION"|"RESTORE"|"BULK"|"GOTO"|"RESTRICT"|"BY"|"GRANT"|"RETURN"|"CASCADE"|"GROUP"|"REVERT"|"CASE"|"HAVING"|"REVOKE"|"CHECK"|"HOLDLOCK"|"RIGHT"|"CHECKPOINT"|"IDENTITY"|"ROLLBACK"|"CLOSE"|"IDENTITY_INSERT"|"ROWCOUNT"|"CLUSTERED"|"IDENTITYCOL"|"ROWGUIDCOL"|"COALESCE"|"IF"|"RULE"|"COLLATE"|"IN"|"SAVE"|"COLUMN"|"INDEX"|"SCHEMA"|"COMMIT"|"INNER"|"SECURITYAUDIT"|"COMPUTE"|"INSERT"|"SELECT"|"CONSTRAINT"|"INTERSECT"|"SESSION_USER"|"CONTAINS"|"INTO"|"SET"|"CONTAINSTABLE"|"IS"|"SETUSER"|"CONTINUE"|"JOIN"|"SHUTDOWN"|"CONVERT"|"KEY"|"SOME"|"CREATE"|"KILL"|"STATISTICS"|"CROSS"|"LEFT"|"SYSTEM_USER"|"CURRENT"|"LIKE"|"TABLE"|"CURRENT_DATE"|"LINENO"|"TABLESAMPLE"|"CURRENT_TIME"|"LOAD"|"TEXTSIZE"|"CURRENT_TIMESTAMP"|"MERGE"|"THEN"|"CURRENT_USER"|"NATIONAL"|"TO"|"CURSOR"|"NOCHECK"|"TOP"|"DATABASE"|"NONCLUSTERED"|"TRAN"|"DBCC"|"NOT"|"TRANSACTION"|"DEALLOCATE"|"NULL"|"TRIGGER"|"DECLARE"|"NULLIF"|"TRUNCATE"|"DEFAULT"|"OF"|"TSEQUAL"|"DELETE"|"OFF"|"UNION"|"DENY"|"OFFSETS"|"UNIQUE"|"DESC"|"ON"|"UNPIVOT"|"DISK"|"OPEN"|"UPDATE"|"DISTINCT"|"OPENDATASOURCE"|"UPDATETEXT"|"DISTRIBUTED"|"OPENQUERY"|"USE"|"DOUBLE"|"OPENROWSET"|"USER"|"DROP"|"OPENXML"|"VALUES"|"DUMP"|"OPTION"|"VARYING"|"ELSE"|"OR"|"VIEW"|"END"|"ORDER"|"WAITFOR"|"ERRLVL"|"OUTER"|"WHEN"|"ESCAPE"|"OVER"|"WHERE"|"EXCEPT"|"PERCENT"|"WHILE"|"EXEC"|"PIVOT"|"WITH"|"EXECUTE"|"PLAN"|"WRITETEXT"
RString "N"\'{1}.*\'{1}
RInteger [0-9]+
RDigit [0-9\.]+
RBlank      [ \t\r\n]+
RMethodName ([_a-zA-Z\[-\]]+"."{1}[_a-zA-Z0-9\[-\]]+)|[_a-zA-Z0-9\[-\]]+
RVariableName   "@"[_a-zA-Z0-9]+
RVariableType   [_a-zA-z0-9]+
RVariableValue  "NULL"|"@"[_a-zA-Z0-9]+|\'{1}.*\'{1}|[0-9\.]+|"N"\'{1}.*\'{1}

%%

"CREATE"{RBlank}"PROCEDURE" {
    m_oDeclaration.StartingLine(yylineno);
    m_eStage = E_STAGE_PRCEDURE_DECLARATION;
    m_eMatched = E_MATCHED_DECLARATION;

    BEGIN M_PROCEDURE_DECLARATION;
}

<M_PROCEDURE_DECLARATION>{RMethodName} {
    if(E_MATCHED_DECLARATION == m_eMatched)
    {
        m_oDeclaration.Name(yytext);
    }
}

<M_PROCEDURE_DECLARATION>"(" {
    if(E_MATCHED_DECLARATION == m_eMatched)
    {
        m_stlLeftBraces.push_back("(");

        BEGIN M_DECLARE_VARIABLE;
    }
    else
    {
        //TODO: stop and throw exception
    }
}

<M_PROCEDURE_DECLARATION>")" {
    //TODO: stop and throw exception
    ;
}

<M_PROCEDURE_DECLARATION>. {
    ;
}

<M_PROCEDURE_DECLARATION_END>"AS" {
    m_oDeclaration.EndingLine(yylineno);

    oDriver.Declaration(m_oDeclaration);
    //Do not clear declaration.
    m_eStage = E_STAGE_BODY;

    BEGIN INITIAL;
}

<M_DECLARE_VARIABLE>{RVariableName} {
    m_eMatched = E_MATCHED_PARAMETER_NAME;
    m_oVariable.StartingLine(yylineno);
    m_oVariable.Name(yytext);
}

<M_DECLARE_VARIABLE>{RVariableType} {
    //Double check prev matched is variable name
    if(E_MATCHED_PARAMETER_NAME == m_eMatched)
    {
        m_eMatched = E_MATCHED_PARAMETER_TYPE;
        m_oVariable.Type(yytext);
    }
    else
    {
        //TODO: stop and throw exception
    }
}

<M_DECLARE_VARIABLE>"("{RInteger} {
    m_stlLeftBraces.push_back("(");

    //Double check variable type
    if(E_MATCHED_PARAMETER_TYPE == m_eMatched)
    {
        m_oVariable.Type(m_oVariable.Type().append(yytext));
    }
    else
    {
        //TODO: stop and throw exception
    }
}

<M_DECLARE_VARIABLE>")" {
    m_stlLeftBraces.pop_back();

    if(m_stlLeftBraces.size() == 0)
    {
        if(InDeclaration())
        {
            m_oVariable.EndingLine(yylineno);
            m_oDeclaration.AddParameter(m_oVariable);
            m_oVariable.Clear();

            if(E_STAGE_PRCEDURE_DECLARATION == m_eStage)
            {
                BEGIN M_PROCEDURE_DECLARATION_END;
            }
            else
            {
                BEGIN M_FUNCTION_DECLARATION;
            }
        }
        else
        {
            //TODO: stop and throw exception
        }
    }
    else
    {
        if(E_MATCHED_PARAMETER_TYPE == m_eMatched)
        {
            m_oVariable.Type(m_oVariable.Type().append(")"));
        }
        else
        {
            //TODO: stop and throw exception
        }
    }
}

<M_DECLARE_VARIABLE>"="{RBlank}{RVariableValue} {
    if(E_MATCHED_PARAMETER_TYPE == m_eMatched)
    {
        m_eMatched = E_MATCHED_PARAMETER_VALUE;
        m_oVariable.Value(yytext);
    }
    else
    {
        //TODO: stop and throw exception
    }
}

<M_DECLARE_VARIABLE>{RBlank}"OUTPUT" {
    if(E_MATCHED_PARAMETER_VALUE == m_eMatched || E_MATCHED_PARAMETER_TYPE == m_eMatched)
    {
        m_oVariable.Output(true);
    }
    else
    {
        //TODO: stop and throw exception
    }
}

<M_DECLARE_VARIABLE>"," {
    if(E_MATCHED_PARAMETER_VALUE == m_eMatched || E_MATCHED_PARAMETER_TYPE == m_eMatched)
    {
        m_oVariable.EndingLine(yylineno);
        m_oDeclaration.AddParameter(m_oVariable);
        m_oVariable.Clear();
    }
    else
    {
        //TODO: stop and throw exception
    }
}

<M_DECLARE_VARIABLE>. {
    ;
}

"EXEC"{RBlank}{RMethodName} {
    m_oProcedure.StartingLine(yylineno);
    m_oProcedure.Name(yytext);
    m_eStage = E_STAGE_PROCEDURE;
    m_eMatched = E_MATCHED_PROCEDURE;

    BEGIN M_PROCEDURE;
}

"EXEC"{RBlank}{RVariableName}{RBlank}"="{RBlank}({RVariableName}|{RString}) {
    m_oProcedure.StartingLine(yylineno);
    m_oProcedure.Name(yytext);
    m_eStage = E_STAGE_PROCEDURE;
    m_eMatched = E_MATCHED_PROCEDURE;

    BEGIN M_PROCEDURE;
}

<M_PROCEDURE>"="{1} {
    if(E_MATCHED_ARGUMENT_VALUE == m_eMatched)
    {
        m_eMatched = E_MATCHED_ARGUMENT_SWAP;
    }
    else
    {
        //TODO: stop and throw exception
    }
}

<M_PROCEDURE>{RVariableValue} {
    if(E_MATCHED_PROCEDURE == m_eMatched || E_MATCHED_ARGUMENT_VALUE == m_eMatched)
    {
        m_oArgument.StartingLine(yylineno);
        m_oArgument.RightValue(yytext);
        m_eMatched = E_MATCHED_ARGUMENT_VALUE;
    }
    else if(E_MATCHED_ARGUMENT_SWAP == m_eMatched)
    {
        m_oArgument.LeftValue(m_oArgument.RightValue());
        m_oArgument.RightValue(yytext);
        m_eMatched = E_MATCHED_ARGUMENT_VALUE;
    }
    else
    {
        //TODO: stop and throw exception
    }
}

<M_PROCEDURE>"," {
    if(E_MATCHED_ARGUMENT_VALUE == m_eMatched || E_MATCHED_PROCEDURE == m_eMatched)
    {
        m_oArgument.EndingLine(yylineno);
        m_oProcedure.AppendArgument(m_oArgument);
        m_oArgument.Clear();
    }
    else
    {
        //TODO: stop and throw exception
    }
}

<M_PROCEDURE>"OUTPUT" {
    if(E_MATCHED_ARGUMENT_VALUE == m_eMatched)
    {
        m_oArgument.Output(true);
    }
    else
    {
        //TODO: stop and throw exception
    }
}


<M_PROCEDURE>{RBlank}/{RKeyword} {
    m_oArgument.EndingLine(yylineno);
    m_oProcedure.AppendArgument(m_oArgument);
    m_oArgument.Clear();
    m_oProcedure.EndingLine(yylineno);

    oDriver.Procedure(m_oProcedure);

    m_oProcedure.Clear();

    BEGIN INITIAL;
}

<M_PROCEDURE>. {
    ;
}

.|\n {
    ;
}
%%

namespace SyteLine { namespace Technique { namespace Code
{
    CMssqlScanner::CMssqlScanner(istream* pInStream, ostream* pOutStream)
        :CMssqlScannerFlexLexer(pInStream, pOutStream)
        ,m_eMatched(E_MATCHED_NONE)
    {
    }

    CMssqlScanner::~CMssqlScanner()
    {
    }

    bool CMssqlScanner::InDeclaration()
    {
        return E_STAGE_PRCEDURE_DECLARATION == m_eStage || E_STAGE_FUNCTION_DECLARATION == m_eStage;
    }
}}}

#ifdef yylex
#undef yylex
#endif

int CMssqlScannerFlexLexer::yylex()
{
    std::cerr << "in CMssqlScannerFlexLexer::yylex() !" << std::endl;
    return 0;
}

