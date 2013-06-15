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

    public:
        CPath();
        CPath(WSTRING& sPath);
        CPath(WSTRING& sDirectory, WSTRING& sFileName);
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