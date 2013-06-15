#include "../Capturer.h"

using namespace SyteLine::Technique::Code;

CCapturer::CCapturer()
    :m_nCharacters(0)
    ,m_nLines(0)
{
}

void CCapturer::IncreaseCharacters(size_t nAmount)
{
    m_nCharacters += nAmount;
}

void CCapturer::IncreaseLines(size_t nAmount)
{
    m_nLines += nAmount;
}

const CCapturer& CCapturer::operator=(const CCapturer& oRValue)
{
    m_nCharacters = oRValue.m_nCharacters;
    m_nLines = oRValue.m_nLines;

    return *this;
}