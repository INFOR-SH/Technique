#include "../Path.h"
#include "../String.h"

using namespace SyteLine::Technique;

CPath::CPath()
{
}

CPath::CPath(WSTRING& sPath)
    :m_sPath(sPath)
{
}

CPath::CPath(WSTRING& sDirectory, WSTRING& sFileName)
    :m_sPath(sDirectory)
{
    if(sDirectory[sDirectory.length()-1] != L'\\')
    {
        m_sPath.append(L"\\");
    }

    m_sPath.append(sFileName);
}

CPath::CPath(const CPath& that)
    :m_sPath(that.m_sPath)
{
}

CPath::CPath(const CPath&& that)
{
    *this = move(that);
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
    auto aString = UString::Split(m_sPath, L'\\');

    return aString[aString.size()-1];
}

wstring CPath::Directory() const
{
    wstring sDirectory;

    if(L'\\' == m_sPath[m_sPath.length()-1])
    {
        return m_sPath;
    }
    else
    {
        auto aString = UString::Split(m_sPath, L'\\');

        for(int i = 0; i <aString.size() - 1; i++)
        {
            sDirectory.append(aString[i]);
            sDirectory.append(L"\\");
        }

        return move(sDirectory);
    }
}

const CPath& CPath::operator=(const CPath& rvalue)
{
    m_sPath = rvalue.m_sPath;

    return *this;
}