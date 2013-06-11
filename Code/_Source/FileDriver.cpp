#include "../FileDriver.h"

using namespace SyteLine::Technique::Code;

CFileDriver::CFileDriver()
    :m_nCharacters(0)
    ,m_nLines(0)
{
}

void CFileDriver::IncreaseCharacters(size_t nAmount)
{
    m_nCharacters += nAmount;
}

void CFileDriver::IncreaseLines(size_t nAmount)
{
    m_nLines += nAmount;
}

const CFileDriver& CFileDriver::operator=(const CFileDriver& oRValue)
{
    m_nCharacters = oRValue.m_nCharacters;
    m_nLines = oRValue.m_nLines;

    return *this;
}