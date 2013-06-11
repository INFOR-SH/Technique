#include "../SqlDeclaration.h"
#include "../SqlVariable.h"

using namespace SyteLine::Technique::Code;

CSqlDeclaration::CSqlDeclaration()
{
}

CSqlDeclaration::CSqlDeclaration(const CSqlDeclaration& oThat)
    :CSqlField(oThat)
    ,m_sName(oThat.m_sName)
    ,m_sReturnType(oThat.m_sReturnType)
    ,m_stlParameters(oThat.m_stlParameters)
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

map<mstring, CSqlVariable> CSqlDeclaration::Parameters() const
{
    return m_stlParameters;
}

void CSqlDeclaration::Name(MSTRING& sName)
{
    m_sName = sName;
}

void CSqlDeclaration::ReturnType(MSTRING& sReturnType)
{
    m_sReturnType = sReturnType;
}

void CSqlDeclaration::Parameters(const map<mstring, CSqlVariable>& stlParameters)
{
    m_stlParameters = stlParameters;
}

void CSqlDeclaration::AddParameter(const CSqlVariable& oParameter)
{
    m_stlParameters[oParameter.Name()] = oParameter;
}

CSqlVariable CSqlDeclaration::GetParameter(MSTRING& sName) const
{
    auto aParameter = m_stlParameters.find(sName);

    if(aParameter != m_stlParameters.end())
    {
        return move(CSqlVariable(aParameter->second));
    }
    else
    {
        return CSqlVariable();
    }
}

map<mstring, CSqlVariable>& CSqlDeclaration::QuoteParameters()
{
    return m_stlParameters;
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
    m_stlParameters = oRValue.m_stlParameters;

    return *this;
}