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
        wchar_t m_cDivision;

    public:
        CPath();
        CPath(WSTRING& sPath, wchar_t cDivision=L'\\');
        CPath(WSTRING& sDirectory, WSTRING& sFileName, wchar_t cDivision=L'\\');
        CPath(const CPath& that);
        CPath(const CPath&& that);

        ~CPath();

    public:
        wstring Path() const;
        wstring FileName() const;
        wstring Directory() const;

    public:
        const CPath& operator=(const CPath& rvalue);
    };
}}

#endif