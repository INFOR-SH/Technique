#ifndef SYTELINE_TECHNIQUE_CODE_FILEDRIVER_H
#define SYTELINE_TECHNIQUE_CODE_FILEDRIVER_H

#ifndef SYTELINE_TECHNIQUE_SYSTEM_ECOTOPE_BASE_H
#include "Technique/Ecotope/Base.h"
#endif

namespace SyteLine { namespace Technique { namespace Code
{
    class SYTELINE_LIBRARY_EXPORT CFileDriver
    {
    protected:
        size_t m_nCharacters;
        size_t m_nLines;

    protected:
        CFileDriver();

    public:
        virtual void IncreaseCharacters(size_t nAmount);
        virtual void IncreaseLines(size_t nAmount = 1);

    public:
        virtual const CFileDriver& operator=(const CFileDriver& oRValue);
    };
}}}

#endif
