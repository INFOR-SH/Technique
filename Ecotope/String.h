#ifndef SYTELINE_TECHNIQUE_ECOTOPE_STRING_H
#define SYTELINE_TECHNIQUE_ECOTOPE_STRING_H

#ifndef SYTELINE_SYSTEM_ECOTOPE_BASE_H
#include "Technique/Ecotope/Base.h"
#endif

namespace SyteLine { namespace Technique
{
    const static wstring WS_BLANK = L"";
    const static string MS_BLANK = "";

    struct SYTELINE_LIBRARY_EXPORT UString
    {
        static const size_t N_BUFFER_SIZE = 255;

        inline static wstring ToWideString(const string& msInput, bool bAppended = false);
        inline static string ToMultipleString(wstring& wsInput, bool bAppended = false);
    };
}}

#endif
