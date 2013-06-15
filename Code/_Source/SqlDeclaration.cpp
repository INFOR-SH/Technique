#include "../SqlDeclaration.h"
#include "Technique/Ecotope/String.h"

using namespace SyteLine::Technique;
using namespace SyteLine::Technique::Code;

CSqlDeclaration::CSqlDeclaration()
{
}

CSqlDeclaration::CSqlDeclaration(const CSqlDeclaration& oThat)
    :CSqlField(oThat)
    ,m_sName(oThat.m_sName)
    ,m_sReturnType(oThat.m_sReturnType)
    ,m_oParameters(oThat.m_oParameters)
{
}

CSqlDeclaration::CSqlDeclaration(const CSqlDeclaration&& oThat)
{
    *this = move(oThat);
}

CSqlDeclaration::~CSqlDeclaration()
{
}

mstring CSqlDeclaration::Name() const
{
    return m_sName;
}

mstring CSqlDeclaration::ReturnType() const
{
    return m_sReturnType;
}

CArray<mstring, CSqlVariable> CSqlDeclaration::Parameters() const
{
    return m_oParameters;
}

void CSqlDeclaration::Name(MSTRING& sName)
{
    m_sName = sName;
}

void CSqlDeclaration::ReturnType(MSTRING& sReturnType)
{
    m_sReturnType = sReturnType;
}

void CSqlDeclaration::Parameters(const CArray<mstring, CSqlVariable>& oParameters)
{
    m_oParameters = oParameters;
}

void CSqlDeclaration::AppendParameter(const CSqlVariable& oParameter)
{
    m_oParameters.Append(UString::ToLower(oParameter.Name()), oParameter);
}

CSqlVariable CSqlDeclaration::QueryParameter(MSTRING& sName) const
{
    return m_oParameters.Query(UString::ToLower(sName));
}

CArray<mstring, CSqlVariable>& CSqlDeclaration::QuoteParameters()
{
    return m_oParameters;
}

mstring CSqlDeclaration::ToString(size_t nTabSize)
{
    return "";
}

const CSqlDeclaration& CSqlDeclaration::operator=(const CSqlDeclaration& oRValue)
{
    CSqlField::operator=(oRValue);

    m_sName = oRValue.m_sName;
    m_sReturnType = oRValue.m_sReturnType;
    m_oParameters = oRValue.m_oParameters;

    return *this;
}