#include "../String.h"

using namespace SyteLine::Technique;

wstring UString::ToWideString(const string& sInput, bool bAppended)
{
    size_t nMbsStringLength = sInput.length();
    wstring sOutput = WS_BLANK;

    if(nMbsStringLength > 0)
    {
        size_t Offerset = 0;

        while(Offerset < nMbsStringLength)
        {
            wchar_t wcsBuffer[N_BUFFER_SIZE+1] = {0};

            size_t nConvertedCharacters = mbstowcs(wcsBuffer, sInput.c_str() + Offerset, N_BUFFER_SIZE);
            if(nConvertedCharacters == -1)
            {
                return WS_BLANK;
            }

            Offerset += nConvertedCharacters;

            wcsBuffer[nConvertedCharacters] = L'\0';

            sOutput.append(wcsBuffer);
        }
    }

    return sOutput;
}

string UString::TrimLeftBlank(MSTRING& sInput)
{
    string sReturn;
    size_t nLength = sInput.length();

    if(0 != nLength)
    {
        for(size_t i = 0; i < sInput.length(); i++)
        {
            if(sInput[i] != ' ' && sInput[i] != '\t' && sInput[i] != '\r' && sInput[i] != '\n')
            {
                sReturn = sInput.substr(i);

                break;
            }
        }
    }

    return move(sReturn);
}

string UString::TrimRightBlank(MSTRING& sInput)
{
    string sReturn;
    size_t nLength = sInput.length();

    if(0 != nLength)
    {
        for(size_t i = nLength-1; i >= 0; i--)
        {
            if(sInput[i] != ' ' && sInput[i] != '\t' && sInput[i] != '\r' && sInput[i] != '\n')
            {
                sReturn = sInput.substr(0, i+1);

                break;
            }
        }
    }

    return move(sReturn);
}

string UString::TrimBlank(MSTRING& sInput)
{
    return TrimRightBlank(TrimLeftBlank(sInput));
}

vector<string> UString::Split(MSTRING& sInput, char cSeparator)
{
    string sOpertion(sInput);
    vector<string> stlStrings;
    size_t nIndex;

    while((nIndex = sOpertion.find(cSeparator)) != -1)
    {
        stlStrings.push_back(sOpertion.substr(0, nIndex));

        sOpertion = sOpertion.substr(nIndex+1, sOpertion.length());
    }

    if(sOpertion.length() > 0)
    {
        stlStrings.push_back(sOpertion);
    }

    return move(stlStrings);
}