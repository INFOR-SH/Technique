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

mstring UString::TrimLeftBlank(MSTRING& sInput)
{
    mstring sResult;
    size_t nLength = sInput.length();

    if(0 != nLength)
    {
        for(size_t i = 0; i < sInput.length(); i++)
        {
            if(sInput[i] != ' ' && sInput[i] != '\t' && sInput[i] != '\r' && sInput[i] != '\n')
            {
                sResult = sInput.substr(i);

                break;
            }
        }
    }

    return move(sResult);
}

wstring UString::TrimLeftBlank(WSTRING& sInput)
{
    wstring sResult;
    size_t nLength = sInput.length();

    if(0 != nLength)
    {
        for(size_t i = 0; i < sInput.length(); i++)
        {
            if(sInput[i] != L' ' && sInput[i] != L'\t' && sInput[i] != L'\r' && sInput[i] != L'\n')
            {
                sResult = sInput.substr(i);

                break;
            }
        }
    }

    return move(sResult);
}

mstring UString::TrimRightBlank(MSTRING& sInput)
{
    mstring sReturn;
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


wstring UString::TrimRightBlank(WSTRING& sInput)
{
    wstring sResult;
    size_t nLength = sInput.length();

    if(0 != nLength)
    {
        for(size_t i = nLength-1; i >= 0; i--)
        {
            if(sInput[i] != L' ' && sInput[i] != L'\t' && sInput[i] != L'\r' && sInput[i] != L'\n')
            {
                sResult = sInput.substr(0, i+1);

                break;
            }
        }
    }

    return move(sResult);
}

mstring UString::TrimBlank(MSTRING& sInput)
{
    return TrimRightBlank(TrimLeftBlank(sInput));
}

wstring UString::TrimBlank(WSTRING& sInput)
{
    return TrimRightBlank(TrimLeftBlank(sInput));
}

vector<mstring> UString::Split(MSTRING& sInput, char tSeparator)
{
    mstring sOpertion(sInput);
    vector<mstring> stlStrings;
    size_t nIndex;

    while((nIndex = sOpertion.find(tSeparator)) != -1)
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

vector<wstring> UString::Split(WSTRING& sInput, wchar_t tSeparator)
{
    wstring sOpertion(sInput);
    vector<wstring> stlStrings;
    size_t nIndex;

    while((nIndex = sOpertion.find(tSeparator)) != -1)
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

mstring UString::ToLower(MSTRING& sInput)
{
    mstring sResult = sInput;

    transform(sResult.begin(), sResult.end(), sResult.begin(), tolower);

    return move(sResult);
}

wstring UString::ToLower(WSTRING& sInput)
{
    wstring sResult = sInput;

    transform(sResult.begin(), sResult.end(), sResult.begin(), tolower);

    return move(sResult);
}

mstring UString::ToUpper(MSTRING& sInput)
{
    mstring sResult = sInput;

    transform(sResult.begin(), sResult.end(), sResult.begin(), toupper);

    return move(sResult);
}

wstring UString::ToUpper(WSTRING& sInput)
{
    wstring sResult = sInput;

    transform(sResult.begin(), sResult.end(), sResult.begin(), toupper);

    return move(sResult);
}