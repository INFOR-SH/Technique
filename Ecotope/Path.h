#ifndef SYTELINE_TECHNIQUE_ECOTOPE_PATH_H
#define SYTELINE_TECHNIQUE_ECOTOPE_PATH_H

#ifndef SYTELINE_SYSTEM_ECOTOPE_BASE_H
#include "Technique/Ecotope/Base.h"
#endif

namespace SyteLine { namespace Technique
{
    class SYTELINE_LIBRARY_EXPORT CPath
    {
    private:
        wstring m_sPath;
        wstring m_sDirectoryCharacter;

    public:
        CPath();
        CPath(WSTRING& sPath, WSTRING& cDirectoryCharacter = L"\\");
        CPath(WSTRING& sDirectory, WSTRING& sFileName, WSTRING& cDirectoryCharacter = L"\\");
        CPath(const CPath& oThat);
        CPath(const CPath&& oThat);
        ~CPath();

    public:
        wstring Path() const;
        wstring FileName() const;
        wstring Directory() const;

    public:
        const CPath& operator=(const CPath& oRValue);
    };
}}

#endif