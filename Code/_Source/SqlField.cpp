#include "../SqlField.h"

using namespace SyteLine::Technique::Code;

CSqlField::CSqlField()
    :m_nStartingLine(0)
    ,m_nEndingLine(0)
{
}

CSqlField::CSqlField(const CSqlField& oThat)
    :m_nStartingLine(oThat.m_nStartingLine)
    ,m_nEndingLine(oThat.m_nEndingLine)
{
}

CSqlField::CSqlField(const CSqlField&& oThat)
{
    *this = move(oThat);
}

CSqlField::~CSqlField()
{
}

size_t CSqlField::StartingLine() const
{
    return m_nStartingLine;
}

size_t CSqlField::EndingLine() const
{
    return m_nEndingLine;
}

void CSqlField::StartingLine(size_t nLine)
{
    m_nStartingLine = nLine;
}

void CSqlField::EndingLine(size_t nLine)
{
    m_nEndingLine = nLine;
}


void CSqlField::Clear()
{
    m_nStartingLine = 0;
    m_nEndingLine = 0;
}

const CSqlField& CSqlField::operator=(const CSqlField& oRValue)
{
    m_nStartingLine = oRValue.m_nStartingLine;
    m_nEndingLine = oRValue.m_nEndingLine;

    return *this;
}
