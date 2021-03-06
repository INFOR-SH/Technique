#include "Technique/Code/MssqlCapturer.h"
#include "Technique/Code/MssqlScanner.h"
#include "Technique/Code/SqlDeclaration.h"
#include "Technique/Code/SqlProcedure.h"
#include "Technique/Code/SqlVariable.h"
#include "Technique/Ecotope/String.h"

using namespace SyteLine::Technique;
using namespace SyteLine::Technique::Code;

//CSqlParameter GetLastParameter(CMssqlCapturer& pCapturer)
//{
//    auto stlParameters = pCapturer.Parameters();
//    size_t nLastLine = 0;
//    mstring sLastName = "";
//
//    for(auto parameter = stlParameters.begin(); parameter != stlParameters.end(); parameter++)
//    {
//        if(parameter->second.Lines() > nLastLine)
//        {
//            nLastLine = parameter->second.Lines();
//            sLastName = parameter->first;
//        }
//    }
//
//    return move(CSqlParameter(stlParameters[sLastName]));
//}
//
//void Output(const CSqlParameter& oLastParameter, mstring sInputFileFullName, mstring sOutputFileFullName)
//{
//    ifstream stlInputFileStream(sInputFileFullName);
//    ofstream stlOuptuFileStream(sOutputFileFullName, ios::trunc);
//    char csBuffer[2048] = {0};
//    size_t nReadLine = 1;
//    mstring sInserted = "   , @UserId   TokenType   =   NULL";
//
//    while(stlInputFileStream.getline(csBuffer,2048))
//    {
//        if(nReadLine == oLastParameter.Lines()+1)
//        {
//            stlOuptuFileStream.write(sInserted.c_str(), sInserted.length());
//            stlOuptuFileStream.write("\n", strlen("\n"));
//        }
//
//        stlOuptuFileStream.write(csBuffer, strlen(csBuffer));
//        stlOuptuFileStream.write("\n", strlen("\n"));
//
//        memset(csBuffer, 0, sizeof(csBuffer));
//        nReadLine++;
//    }
//
//    stlInputFileStream.close();
//    stlOuptuFileStream.close();
//}

bool Output(const CMssqlCapturer& pCapturer, mstring sInputFileName, mstring sOutputFileName)
{
    bool bResult = true;
    string sOldSpName("InitSessionContextSp");
    string sNewSpName("InitSessionContextWithUserSp");
    CSqlFile oSqlFile = pCapturer.GetSqlFile();
    auto aParameters = oSqlFile.Declaration().Parameters();
    CSqlProcedure oProcedure = oSqlFile.GetProcedure(sOldSpName);
    CSqlVariable oLastParameter(aParameters.Last());
    CSqlArgument oLastArgument(oProcedure.QuoteArguments().Last());

    ifstream stlInputFileStream(sInputFileName);
    ofstream stlOuptuFileStream(sOutputFileName, ios::trunc);

    char csBuffer[2048] = {0};
    size_t nReadLine = 1;
    mstring sInsertParameter = "   , @UserId   TokenType   =   NULL\n";
    mstring sInsertArgument = "   , @UserName = @UserId\n";
    int nReplaced = 0;

    while(stlInputFileStream.getline(csBuffer,2048))
    {
        if(nReadLine == oLastParameter.EndingLine())
        {
            mstring sLine(csBuffer);
            size_t nIndex = sLine.find_last_of(")");

            if(nIndex == -1)
            {
                stlOuptuFileStream.write(csBuffer, strlen(csBuffer));
                stlOuptuFileStream.write("\n", strlen("\n"));
                stlOuptuFileStream.write(sInsertParameter.c_str(), sInsertParameter.length());
            }
            else
            {
                string sFirstWritten = sLine.substr(0, nIndex);
                string sLastWritten = sLine.substr(nIndex, sLine.length()-nIndex);

                stlOuptuFileStream.write(sFirstWritten.c_str(), sFirstWritten.length());
                stlOuptuFileStream.write("\n", strlen("\n"));
                stlOuptuFileStream.write(sInsertParameter.c_str(), sInsertParameter.length());
                stlOuptuFileStream.write(sLastWritten.c_str(), sLastWritten.length());
                stlOuptuFileStream.write("\n", strlen("\n"));
            }
        }
        else if(nReadLine >= oProcedure.StartingLine() && nReadLine <= oProcedure.EndingLine())
        {
            if(nReplaced == 0)
            {
                mstring sLine(csBuffer);
                size_t nIndex = sLine.find(sOldSpName);

                if(nIndex == -1)
                {
                    if(nReadLine== oProcedure.EndingLine())
                    {
                        bResult = false;
                        goto RET;
                    }
                    else
                    {
                        stlOuptuFileStream.write(csBuffer, strlen(csBuffer));
                        stlOuptuFileStream.write("\n", strlen("\n"));
                    }
                }
                else
                {
                    string sFirstWritten = sLine.substr(0, nIndex);
                    string sLastWritten = sLine.substr(nIndex + sOldSpName.length(), sLine.length() - nIndex - sOldSpName.length());

                    stlOuptuFileStream.write(sFirstWritten.c_str(), sFirstWritten.length());
                    stlOuptuFileStream.write(sNewSpName.c_str(), sNewSpName.length());
                    stlOuptuFileStream.write(sLastWritten.c_str(), sLastWritten.length());
                    stlOuptuFileStream.write("\n", strlen("\n"));

                    nReplaced = 1;
                }
            }
            else if(nReplaced == 1)
            {
                if(nReadLine == oLastArgument.EndingLine())
                {
                    mstring sLine(csBuffer);
                    size_t nIndex = sLine.find_last_of("/");

                    if(nIndex == -1)
                    {
                        stlOuptuFileStream.write(csBuffer, strlen(csBuffer));
                        stlOuptuFileStream.write("\n", strlen("\n"));
                        stlOuptuFileStream.write(sInsertArgument.c_str(), sInsertArgument.length());
                    }
                    else
                    {
                        string sFirstWritten = sLine.substr(0, nIndex);
                        string sLastWritten = sLine.substr(nIndex, sLine.length()-nIndex);

                        stlOuptuFileStream.write(sFirstWritten.c_str(), sFirstWritten.length());
                        stlOuptuFileStream.write("\n", strlen("\n"));
                        stlOuptuFileStream.write(sInsertArgument.c_str(), sInsertArgument.length());
                        stlOuptuFileStream.write(sLastWritten.c_str(), sLastWritten.length());
                        stlOuptuFileStream.write("\n", strlen("\n"));
                    }

                    nReplaced = 2;
                }
                else
                {
                    stlOuptuFileStream.write(csBuffer, strlen(csBuffer));
                    stlOuptuFileStream.write("\n", strlen("\n"));
                }
            }
            else
            {
                stlOuptuFileStream.write(csBuffer, strlen(csBuffer));
                stlOuptuFileStream.write("\n", strlen("\n"));
            }
        }
        else
        {
            stlOuptuFileStream.write(csBuffer, strlen(csBuffer));
            stlOuptuFileStream.write("\n", strlen("\n"));
        }

        memset(csBuffer, 0, sizeof(csBuffer));
        nReadLine++;
    }

RET:
    stlInputFileStream.close();
    stlOuptuFileStream.close();

    return bResult;
}

void main()
{
    mstring sInputFileName("D:\\Rpt_1099FormPrintingSp.sp");
    mstring sOutputFileName("D:\\Rpt_1099FormPrintingSp.output.sql");
    ifstream stlInputFileStream(sInputFileName);
    CMssqlCapturer pCapturer;
    CMssqlScanner oScanner(&stlInputFileStream);

    oScanner.Flex(pCapturer);

    stlInputFileStream.close();

    Output(pCapturer, sInputFileName, sOutputFileName);

}