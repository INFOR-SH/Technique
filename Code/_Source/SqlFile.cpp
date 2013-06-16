#include "../SqlFile.h"
#include "../SqlVariable.h"
#include "../SqlArgument.h"

using namespace SyteLine::Technique;
using namespace SyteLine::Technique::Code;

CSqlFile::CSqlFile()
{
}

CSqlFile::CSqlFile(const CSqlFile& that)
    :m_oDeclaration(that.m_oDeclaration)
    ,m_oProcedures(that.m_oProcedures)
{
}

CSqlFile::CSqlFile(const CSqlFile&& that)
{
    *this = move(that);
}

CSqlFile::~CSqlFile()
{
}

void CSqlFile::Declaration(const CSqlDeclaration& oDeclaration)
{
    m_oDeclaration = oDeclaration;
}

CSqlDeclaration CSqlFile::Declaration() const
{
    return m_oDeclaration;
}

void CSqlFile::Procedures(const CCollection<wstring, CSqlProcedure>& oProcedures)
{
    m_oProcedures = oProcedures;
}

CCollection<wstring, CSqlProcedure> CSqlFile::Procedures() const
{
    return m_oProcedures;
}

void CSqlFile::AppendProcedure(const CSqlProcedure& oProcedure)
{
    wstring sKey = UString::ToLower(oProcedure.ToFullName());

    m_oProcedures.Append(sKey, oProcedure);
}

CQueried<CSqlVariable> CSqlFile::QueryParameter(WSTRING& sName) const
{
    wstring sKey = UString::ToLower(sName);

    return m_oDeclaration.QueryParameter(sKey);
}

CQueried<CSqlProcedure> CSqlFile::QueryProcedure(WSTRING& sName) const
{
    wstring sKey = UString::ToLower(sName);

    return m_oProcedures.Query(CSqlProcedure::MakeFullName(sKey));
}

CSqlDeclaration& CSqlFile::QuoteDeclaration()
{
    return m_oDeclaration;
}

CCollection<wstring, CSqlProcedure>& CSqlFile::QuoteProcedures()
{
    return m_oProcedures;
}

const CSqlFile& CSqlFile::operator=(const CSqlFile& rvalue)
{
    m_oDeclaration = rvalue.m_oDeclaration;
    m_oProcedures = rvalue.m_oProcedures;

    return *this;
}