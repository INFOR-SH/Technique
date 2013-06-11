#include "../MssqlDriver.h"
#include "../SqlVariable.h"
#include "../SqlDeclaration.h"
#include "../SqlProcedure.h"

using namespace SyteLine::Technique::Code;

CMssqlDriver::CMssqlDriver()
{
}

CMssqlDriver::CMssqlDriver(const CMssqlDriver& oThat)
    :CFileDriver(oThat)
    ,m_oSqlFile(oThat.m_oSqlFile)
{
}

CMssqlDriver::~CMssqlDriver()
{
}

void CMssqlDriver::Declaration(const CSqlDeclaration& oDeclaration)
{
    m_oSqlFile.Declaration(oDeclaration);
}

void CMssqlDriver::Variable(const CSqlVariable& oVariable)
{
}

void CMssqlDriver::Procedure(const CSqlProcedure& oProcedure)
{
    m_oSqlFile.AddProcedure(oProcedure);
}

CSqlVariable CMssqlDriver::QueryParameter(MSTRING& sName)
{
    return m_oSqlFile.QuoteDeclaration().GetParameter(sName);
}

CSqlDeclaration CMssqlDriver::Declaration() const
{
    return m_oSqlFile.Declaration();
}

vector<CSqlProcedure> CMssqlDriver::Procedures() const
{
    return m_oSqlFile.Procedures();
}

const CMssqlDriver& CMssqlDriver::operator=(const CMssqlDriver& oRValue)
{
    CFileDriver::operator=(oRValue);
    
    m_oSqlFile = oRValue.m_oSqlFile;

    return *this;
}