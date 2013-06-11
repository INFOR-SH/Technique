#include "../SqlProcedure.h"
#include "../SqlArgument.h"
#include "Technique/Ecotope/String.h"

using namespace SyteLine::Technique::Code;

CSqlProcedure::CSqlProcedure()
{
}

CSqlProcedure::CSqlProcedure(const CSqlProcedure& oThat)
    :CSqlField(oThat)
    ,m_sName(oThat.m_sName)
    ,m_stlArguments(oThat.m_stlArguments)
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

mstring CSqlProcedure::ReturnValue() const
{
   return m_sReturnValue;
}

void CSqlProcedure::Name(MSTRING& sName)
{
    m_sName = sName;
}

void CSqlProcedure::ReturnValue(MSTRING& sReturnValue)
{
    m_sReturnValue = sReturnValue;
}

void CSqlProcedure::AppendArgument(const CSqlArgument& oArgument)
{
    m_stlArguments.push_back(oArgument);
}

vector<CSqlArgument>& CSqlProcedure::QuoteArguments()
 {
     return m_stlArguments;
 }

void CSqlProcedure::Clear()
{
    CSqlField::Clear();

    m_sName = MS_BLANK;
    m_stlArguments.clear();
}

 const CSqlProcedure& CSqlProcedure::operator=(const CSqlProcedure& oRValue)
{
    CSqlField::operator=(oRValue);

    m_sName = oRValue.m_sName;
    m_stlArguments = oRValue.m_stlArguments;

    return *this;
}