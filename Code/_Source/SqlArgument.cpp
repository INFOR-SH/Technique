#include "../SqlArgument.h"
#include "Technique/Ecotope/String.h"

using namespace SyteLine::Technique::Code;

CSqlArgument::CSqlArgument()
    :m_bOutput(false)
{
}

CSqlArgument::CSqlArgument(const CSqlArgument& oThat)
    :CSqlField(oThat)
    ,m_sLeftValue(oThat.m_sLeftValue)
    ,m_sRightValue(oThat.m_sRightValue)
    ,m_bOutput(oThat.m_bOutput)
{
}

CSqlArgument::CSqlArgument(const CSqlArgument&& oThat)
{
    *this = move(oThat);
}

CSqlArgument::~CSqlArgument()
{
}

mstring CSqlArgument::LeftValue() const
{
    return m_sLeftValue;
}

mstring CSqlArgument::RightValue() const
{
    return m_sRightValue;
}

bool CSqlArgument::Output() const
{
    return m_bOutput;
}

void CSqlArgument::LeftValue(MSTRING& sValue)
{
    m_sLeftValue = sValue;
}

void CSqlArgument::RightValue(MSTRING& sValue)
{
    m_sRightValue = sValue;
}

void CSqlArgument::Output(bool bOutput)
{
    m_bOutput = bOutput;
}

void CSqlArgument::Clear()
{
    CSqlField::Clear();

    m_sLeftValue = MS_BLANK;
    m_sRightValue = MS_BLANK;
    m_bOutput = false;
}

const CSqlArgument& CSqlArgument::operator=(const CSqlArgument& oRValue)
{
    CSqlField::operator=(oRValue);

    m_sLeftValue = oRValue.m_sLeftValue;
    m_sRightValue = oRValue.m_sRightValue;
    m_bOutput = oRValue.m_bOutput;

    return *this;
}
