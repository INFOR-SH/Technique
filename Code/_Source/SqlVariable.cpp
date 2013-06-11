#include "../SqlVariable.h"
#include "Technique/Ecotope/String.h"

using namespace SyteLine::Technique::Code;

CSqlVariable::CSqlVariable()
    :m_bOutput(false)
{
}

CSqlVariable::CSqlVariable(const CSqlVariable& oThat)
    :CSqlField(oThat)
    ,m_sName(oThat.m_sName)
    ,m_sType(oThat.m_sType)
    ,m_sValue(oThat.m_sValue)
    ,m_bOutput(oThat.m_bOutput)
{
}

CSqlVariable::CSqlVariable(const CSqlVariable&& oThat)
{
    *this = move(oThat);
}

CSqlVariable::~CSqlVariable()
{
}

mstring CSqlVariable::Name() const
{
    return m_sName;
}

mstring CSqlVariable::Type() const
{
    return m_sType;
}

mstring CSqlVariable::Value() const
{
    return  m_sValue;
}

bool CSqlVariable::Output() const
{
    return m_bOutput;
}

void CSqlVariable::Name(MSTRING& sName)
{
    m_sName = sName;
}

void CSqlVariable::Type(MSTRING& sType)
{
    m_sType = sType;
}

void CSqlVariable::Value(MSTRING& sValue)
{
    m_sValue = sValue;
}

void CSqlVariable::Output(bool bOutput)
{
    m_bOutput = bOutput;
}

void CSqlVariable::Clear()
{
    CSqlField::Clear();

    m_sName = MS_BLANK;
    m_sType = MS_BLANK;
    m_sValue = MS_BLANK;
    m_bOutput = false;
}

const CSqlVariable& CSqlVariable::operator=(const CSqlVariable& oRValue)
{
    CSqlField::operator=(oRValue);

    m_sName = oRValue.m_sName;
    m_sType = oRValue.m_sType;
    m_sValue = oRValue.m_sValue;
    m_bOutput = oRValue.m_bOutput;

    return *this;
}
