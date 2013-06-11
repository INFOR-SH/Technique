#include "../String.h"

using namespace SyteLine::Technique;

wstring UString::ToWideString(const string& msInput, bool bAppended)
{
    size_t nMbsStringLength = msInput.length();
    wstring wsOutput = WS_BLANK;

    if(nMbsStringLength > 0)
    {
        size_t Offerset = 0;

        while(Offerset < nMbsStringLength)
        {
            wchar_t wcsBuffer[N_BUFFER_SIZE+1] = {0};

            size_t nConvertedCharacters = mbstowcs(wcsBuffer, msInput.c_str() + Offerset, N_BUFFER_SIZE);
            if(nConvertedCharacters == -1)
            {
                return WS_BLANK;
            }

            Offerset += nConvertedCharacters;

            wcsBuffer[nConvertedCharacters] = L'\0';

            wsOutput.append(wcsBuffer);
        }
    }

    return wsOutput;
}
