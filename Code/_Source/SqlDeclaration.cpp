#include "../SqlDeclaration.h"

using namespace SyteLine::Technique;
using namespace SyteLine::Technique::Code;

CSqlDeclaration::CSqlDeclaration()
{
}

CSqlDeclaration::CSqlDeclaration(const CSqlDeclaration& that)
    :CSqlField(that)
    ,m_sName(that.m_sName)
    ,m_sReturnType(that.m_sReturnType)
    ,m_oParameters(that.m_oParameters)
{
}

CSqlDeclaration::CSqlDeclaration(const CSqlDeclaration&& that)
{
    *this = move(that);
}

CSqlDeclaration::~CSqlDeclaration()
{
}

void CSqlDeclaration::Name(WSTRING& sName)
{
    m_sName = sName;
}

wstring CSqlDeclaration::Name() const
{
    return m_sName;
}

void CSqlDeclaration::ReturnType(WSTRING& sReturnType)
{
    m_sReturnType = sReturnType;
}

wstring CSqlDeclaration::ReturnType() const
{
    return m_sReturnType;
}

void CSqlDeclaration::Parameters(const TCollection<wstring, CSqlVariable>& oParameters)
{
    m_oParameters = oParameters;
}

TCollection<wstring, CSqlVariable> CSqlDeclaration::Parameters() const
{
    return m_oParameters;
}

void CSqlDeclaration::AppendParameter(const CSqlVariable& oParameter)
{
    m_oParameters.Append(UString::ToLower(oParameter.Name()), oParameter);
}

TQueried<CSqlVariable>  CSqlDeclaration::QueryParameter(WSTRING& sName) const
{
    return m_oParameters.Query(UString::ToLower(sName));
}

wstring CSqlDeclaration::ToString(size_t nTabSize)
{
    return L"";
}

TCollection<wstring, CSqlVariable>& CSqlDeclaration::QuoteParameters()
{
    return m_oParameters;
}

const CSqlDeclaration& CSqlDeclaration::operator=(const CSqlDeclaration& rvalue)
{
    CSqlField::operator=(rvalue);

    m_sName = rvalue.m_sName;
    m_sReturnType = rvalue.m_sReturnType;
    m_oParameters = rvalue.m_oParameters;

    return *this;
}