#include "../SqlFile.h"
#include "../SqlVariable.h"
#include "Technique/Ecotope/String.h"

using namespace SyteLine::Technique;
using namespace SyteLine::Technique::Code;

CSqlFile::CSqlFile()
{
}

CSqlFile::CSqlFile(const CSqlFile& oThat)
    :m_oDeclaration(oThat.m_oDeclaration)
    ,m_oProcedures(oThat.m_oProcedures)
{
}

CSqlFile::CSqlFile(const CSqlFile&& oThat)
{
    *this = move(oThat);
}

CSqlFile::~CSqlFile()
{
}
void CSqlFile::Declaration(const CSqlDeclaration& oDeclaration)
{
    m_oDeclaration = oDeclaration;
}

void CSqlFile::AppendProcedure(const CSqlProcedure& oProcedure)
{
    m_oProcedures.Append(UString::ToLower(oProcedure.Name()), oProcedure);
}

CSqlDeclaration CSqlFile::Declaration() const
{
    return m_oDeclaration;
}

CArray<mstring, CSqlProcedure> CSqlFile::Procedures() const
{
    return m_oProcedures;
}

CSqlVariable CSqlFile::QueryParameter(MSTRING& sName) const
{
    return m_oDeclaration.QueryParameter(UString::ToLower(sName));
}

CSqlProcedure CSqlFile::QueryProcedure(MSTRING& sName) const
{
    return m_oProcedures.Query(UString::ToLower(sName));
}

CSqlDeclaration& CSqlFile::QuoteDeclaration()
{
    return m_oDeclaration;
}

CArray<mstring, CSqlProcedure>& CSqlFile::QuoteProcedures()
{
    return m_oProcedures;
}

const CSqlFile& CSqlFile::operator=(const CSqlFile& oRValue)
{
    m_oDeclaration = oRValue.m_oDeclaration;
    m_oProcedures = oRValue.m_oProcedures;

    return *this;
}