#ifndef SYTELINE_TECHNIQUE_CODE_CAPTURER_H
#define SYTELINE_TECHNIQUE_CODE_CAPTURER_H

#ifndef SYTELINE_TECHNIQUE_SYSTEM_ECOTOPE_USAGE_H
#include "Technique/Ecotope/Usage.h"
#endif

namespace SyteLine { namespace Technique { namespace Code
{
    class SYTELINE_LIBRARY_EXPORT CCapturer
    {
    protected:
        size_t m_nCharacters;
        size_t m_nLines;

    protected:
        CCapturer();

    public:
        virtual void IncreaseCharacters(size_t nAmount);
        virtual void IncreaseLines(size_t nAmount = 1);

    public:
        virtual const CCapturer& operator=(const CCapturer& rvalue);
    };
}}}

#endif
