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
    ,m_stlParameterIndexs(oThat.m_stlParameterIndexs)
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

vector<CSqlVariable> CSqlDeclaration::Parameters() const
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

void CSqlDeclaration::Parameters(const vector<CSqlVariable>& stlParameters)
{
    m_stlParameters = stlParameters;
}

void CSqlDeclaration::AddParameter(const CSqlVariable& oParameter)
{
    m_stlParameters.push_back(oParameter);
    m_stlParameterIndexs[oParameter.Name()] = m_stlParameters.size() - 1;
}

CSqlVariable CSqlDeclaration::GetParameter(MSTRING& sName) const
{
    auto aIndex = m_stlParameterIndexs.find(sName);

    if(aIndex != m_stlParameterIndexs.end())
    {
        return move(CSqlVariable(m_stlParameters[aIndex->second]));
    }
    else
    {
        return CSqlVariable();
    }
}

vector<CSqlVariable>& CSqlDeclaration::QuoteParameters()
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
    m_stlParameterIndexs = oRValue.m_stlParameterIndexs;

    return *this;
}