#include "../SqlProcedure.h"

using namespace SyteLine::Technique;
using namespace SyteLine::Technique::Code;

CSqlProcedure::CSqlProcedure()
{
}

CSqlProcedure::CSqlProcedure(const CSqlProcedure& that)
    :CSqlField(that)
    ,m_sName(that.m_sName)
    ,m_sReturnVariableName(that.m_sReturnVariableName)
    ,m_oArguments(that.m_oArguments)
{
}

CSqlProcedure::CSqlProcedure(const CSqlProcedure&& that)
{
    *this = move(that);
}

CSqlProcedure::~CSqlProcedure()
{
}

void CSqlProcedure::Name(WSTRING& sName)
{
    m_sName = sName;
}

wstring CSqlProcedure::Name() const
{
    return m_sName;
}

void CSqlProcedure::ReturnVariableName(WSTRING& sReturnVariableName)
{
    m_sReturnVariableName = sReturnVariableName;
}

wstring CSqlProcedure::ReturnVariableName() const
{
   return m_sReturnVariableName;
}

void CSqlProcedure::AppendArgument(const CSqlArgument& oArgument)
{
    wstring sKey = UString::ToLower(oArgument.RightValue());

    m_oArguments.Append(sKey, oArgument);
}

TQueried<CSqlArgument> CSqlProcedure::QueryArgument(WSTRING& sName) const
{
    wstring sKey = UString::ToLower(sName);

    return m_oArguments.Query(sKey);
}

void CSqlProcedure::Clear()
{
    CSqlField::Clear();

    m_sName = S_BLANK;
    m_sReturnVariableName = S_BLANK;
    m_oArguments.Clear();
}

TCollection<wstring, CSqlArgument>& CSqlProcedure::QuoteArguments()
 {
     return m_oArguments;
 }

 const CSqlProcedure& CSqlProcedure::operator=(const CSqlProcedure& rvalue)
{
    CSqlField::operator=(rvalue);

    m_sName = rvalue.m_sName;
    m_sReturnVariableName = rvalue.m_sReturnVariableName;
    m_oArguments = rvalue.m_oArguments;

    return *this;
}