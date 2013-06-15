#include "../MssqlCapturer.h"
#include "../SqlVariable.h"
#include "../SqlDeclaration.h"
#include "../SqlProcedure.h"

using namespace SyteLine::Technique::Code;

CMssqlCapturer::CMssqlCapturer()
{
}

CMssqlCapturer::CMssqlCapturer(const CMssqlCapturer& oThat)
    :CCapturer(oThat)
    ,m_oSqlFile(oThat.m_oSqlFile)
{
}

CMssqlCapturer::~CMssqlCapturer()
{
}

void CMssqlCapturer::CaptureDeclaration(const CSqlDeclaration& oDeclaration)
{
    m_oSqlFile.Declaration(oDeclaration);
}

void CMssqlCapturer::CaptureVariable(const CSqlVariable& oVariable)
{
}

void CMssqlCapturer::CaptureProcedure(const CSqlProcedure& oProcedure)
{
    m_oSqlFile.AppendProcedure(oProcedure);
}

CSqlVariable CMssqlCapturer::QueryParameter(MSTRING& sName) const
{
    return m_oSqlFile.QueryParameter(sName);
}

CSqlProcedure CMssqlCapturer::QueryProcedure(MSTRING& sName) const
{
    return m_oSqlFile.QueryProcedure(sName);
}

CSqlFile CMssqlCapturer::GetSqlFile() const
{
    return m_oSqlFile;
}

const CMssqlCapturer& CMssqlCapturer::operator=(const CMssqlCapturer& oRValue)
{
    CCapturer::operator=(oRValue);
    
    m_oSqlFile = oRValue.m_oSqlFile;

    return *this;
}