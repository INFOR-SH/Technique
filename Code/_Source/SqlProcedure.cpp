#include "../SqlProcedure.h"
#include "Technique/Ecotope/String.h"

using namespace SyteLine::Technique;
using namespace SyteLine::Technique::Code;

CSqlProcedure::CSqlProcedure()
{
}

CSqlProcedure::CSqlProcedure(const CSqlProcedure& oThat)
    :CSqlField(oThat)
    ,m_sName(oThat.m_sName)
    ,m_sReturnVariableName(oThat.m_sReturnVariableName)
    ,m_oArguments(oThat.m_oArguments)
{
}

CSqlProcedure::CSqlProcedure(const CSqlProcedure&& oThat)
{
    *this = move(oThat);
}

CSqlProcedure::~CSqlProcedure()
{
}

mstring CSqlProcedure::Name() const
{
    return m_sName;
}

mstring CSqlProcedure::ReturnVariableName() const
{
   return m_sReturnVariableName;
}

void CSqlProcedure::Name(MSTRING& sName)
{
    m_sName = sName;
}

void CSqlProcedure::ReturnVariableName(MSTRING& sReturnVariableName)
{
    m_sReturnVariableName = sReturnVariableName;
}

void CSqlProcedure::AppendArgument(const CSqlArgument& oArgument)
{
    m_oArguments.Append(UString::ToLower(oArgument.RightValue()), oArgument);
}

CSqlArgument CSqlProcedure::QueryArgument(MSTRING& sName) const
{
    return m_oArguments.Query(UString::ToLower(sName));
}

CArray<mstring, CSqlArgument>& CSqlProcedure::QuoteArguments()
 {
     return m_oArguments;
 }

void CSqlProcedure::Clear()
{
    CSqlField::Clear();

    m_sName = MS_BLANK;
    m_sReturnVariableName = MS_BLANK;
    m_oArguments.Clear();
}

 const CSqlProcedure& CSqlProcedure::operator=(const CSqlProcedure& oRValue)
{
    CSqlField::operator=(oRValue);

    m_sName = oRValue.m_sName;
    m_sReturnVariableName = oRValue.m_sReturnVariableName;
    m_oArguments = oRValue.m_oArguments;

    return *this;
}