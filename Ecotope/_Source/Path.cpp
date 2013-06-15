#include "../Path.h"
#include "../String.h"

using namespace SyteLine::Technique;

CPath::CPath()
{
}

CPath::CPath(WSTRING& sPath, WSTRING& sDirectoryCharacter)
    :m_sPath(sPath)
    ,m_sDirectoryCharacter(sDirectoryCharacter)
{
}

CPath::CPath(WSTRING& sDirectory, WSTRING& sFileName, WSTRING& sDirectoryCharacter)
    :m_sPath(sDirectory)
    ,m_sDirectoryCharacter(sDirectoryCharacter)
{
    if(sDirectory[sDirectory.length()-1] != sDirectoryCharacter[0])
    {
        wstring sDirectoryCharacter;

        m_sPath.append(sDirectory);
    }

    m_sPath.append(sFileName);
}

CPath::CPath(const CPath& oThat)
    :m_sPath(oThat.m_sPath)
    ,m_sDirectoryCharacter(oThat.m_sDirectoryCharacter)
{
}

CPath::CPath(const CPath&& oThat)
{
    *this = move(oThat);
}

CPath::~CPath()
{
}

wstring CPath::Path() const
{
    return m_sPath;
}

wstring CPath::FileName() const
{
    if(m_sDirectoryCharacter[0] == m_sPath[m_sPath.length()-1])
    {
        return WS_BLANK;
    }
    else
    {
        auto aString = CWStringHelper(m_sPath).Split(m_sDirectoryCharacter[0]);

        return aString[aString.size()-1];
    }
}

wstring CPath::Directory() const
{
    wstring sDirectory;

    if(m_sDirectoryCharacter[0] == m_sPath[m_sPath.length()-1])
    {
        return m_sPath;
    }
    else
    {
        auto aString = CWStringHelper(m_sPath).Split(m_sDirectoryCharacter[0]);

        for(int i = 0; i <aString.size() - 1; i++)
        {
            sDirectory.append(aString[i]);
            sDirectory.append(m_sDirectoryCharacter);
        }

        return move(sDirectory);
    }
}

const CPath& CPath::operator=(const CPath& oRValue)
{
    m_sPath = oRValue.m_sPath;
    m_sDirectoryCharacter = oRValue.m_sDirectoryCharacter;

    return *this;
}