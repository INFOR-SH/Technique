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
    ,m_sReturnVariableName(oThat.m_sReturnVariableName)
    ,m_stlArguments(oThat.m_stlArguments)
    ,m_stlArgumentIndexs(oThat.m_stlArgumentIndexs)
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
    m_stlArguments.push_back(oArgument);
    m_stlArgumentIndexs[oArgument.RightValue()] = m_stlArguments.size() - 1;
}

CSqlArgument CSqlProcedure::GetArgument(MSTRING& sName) const
{
    auto aIndex = m_stlArgumentIndexs.find(sName);

    if(aIndex != m_stlArgumentIndexs.end())
    {
        return move(CSqlArgument(m_stlArguments[aIndex->second]));
    }
    else
    {
        return CSqlArgument();
    }
}

vector<CSqlArgument>& CSqlProcedure::QuoteArguments()
 {
     return m_stlArguments;
 }

void CSqlProcedure::Clear()
{
    CSqlField::Clear();

    m_sName = MS_BLANK;
    m_sReturnVariableName = MS_BLANK;
    m_stlArguments.clear();
    m_stlArgumentIndexs.clear();
}

 const CSqlProcedure& CSqlProcedure::operator=(const CSqlProcedure& oRValue)
{
    CSqlField::operator=(oRValue);

    m_sName = oRValue.m_sName;
    m_sReturnVariableName = oRValue.m_sReturnVariableName;
    m_stlArguments = oRValue.m_stlArguments;
    m_stlArgumentIndexs = oRValue.m_stlArgumentIndexs;

    return *this;
}