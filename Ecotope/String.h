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

        inline static wstring ToWideString(MSTRING& sInput, bool bAppended = false);
        inline static mstring ToMultipleString(WSTRING& sInput, bool bAppended = false);
        inline static mstring TrimLeftBlank(MSTRING& sInput);
        inline static wstring TrimLeftBlank(WSTRING& sInput);
        inline static mstring TrimRightBlank(MSTRING& sInput);
        inline static wstring TrimRightBlank(WSTRING& sInput);
        inline static mstring TrimBlank(MSTRING& sInput);
        inline static wstring TrimBlank(WSTRING& sInput);
        inline static vector<mstring> Split(MSTRING& sInput, char tSeparator);
        inline static vector<wstring> Split(WSTRING& sInput, wchar_t tSeparator);
        inline static mstring ToLower(MSTRING& sInput);
        inline static wstring ToLower(WSTRING& sInput);
        inline static mstring ToUpper(MSTRING& sInput);
        inline static wstring ToUpper(WSTRING& sInput);
    };

    template<typename TChar>
    class SYTELINE_LIBRARY_EXPORT CStringHelper
    {
    public:
        typedef basic_string<TChar> TString;
        typedef const TString TSTRING;

    private:
        TString m_tString;

    public:
        CStringHelper()
        {
        }

        CStringHelper(TSTRING& tString)
            :m_tString(tString)
        {
        }

        CStringHelper(const CStringHelper<TChar>& oThat)
            :m_tString(oThat.m_tString)
        {
        }

        CStringHelper(const CStringHelper<TChar>&& oThat)
        {
            *this = move(oThat);
        }

    public:
        bool IsBlankCharacter(TChar tCharacter) const
        {
            return (tCharacter == ' ' || tCharacter == '\t' || tCharacter == '\r' || tCharacter == '\n');
        }

        TString TrimLeftBlank() const
        {
            TString tResult;
            size_t nLength = m_tString.length();

            if(0 != nLength)
            {
                for(size_t i = 0; i < m_tString.length(); i++)
                {
                    if(!IsBlankCharacter(m_tString[i]))
                    {
                        tResult = m_tString.substr(i);

                        break;
                    }
                }
            }

            return move(tResult);
        }

        TString TrimRightBlank() const
        {
            TString tResult;
            size_t nLength = m_tString.length();

            if(0 != nLength)
            {
                for(size_t i = nLength-1; i >= 0; i--)
                {
                    if(!IsBlankCharacter(m_tString[i]))
                    {
                        tResult = m_tString.substr(0, i+1);

                        break;
                    }
                }
            }

            return move(tResult);
        }

        TString TrimBlank() const
        {
            return CStringHelper(TrimLeftBlank()).TrimRightBlank();
        }

        vector<TString> Split(TChar tSeparator) const
        {
            TString tOpertion(m_tString);
            vector<TString> stlStrings;
            size_t nIndex;

            while((nIndex = tOpertion.find(tSeparator)) != -1)
            {
                stlStrings.push_back(tOpertion.substr(0, nIndex));

                tOpertion = tOpertion.substr(nIndex+1, tOpertion.length());
            }

            if(tOpertion.length() > 0)
            {
                stlStrings.push_back(tOpertion);
            }

            return move(stlStrings);
        }

        TString ToLower() const
        {
            TString tResult = m_tString;

            transform(tResult.begin(), tResult.end(), tResult.begin(), tolower);

            return move(tResult);
        }

        TString ToUpper() const
        {
            TString tResult = m_tString;

            transform(tResult.begin(), tResult.end(), tResult.begin(), toupper);

            return move(tResult);
        }
    };

    typedef CStringHelper<char> CMStringHelper;
    typedef CStringHelper<wchar_t> CWStringHelper;
}}

#endif
