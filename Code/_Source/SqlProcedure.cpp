#include "../SqlProcedure.h"

using namespace SyteLine::Technique;
using namespace SyteLine::Technique::Code;

wstring CSqlProcedure::MakeFullName(WSTRING& sRawName, WSTRING& sRawOwner)
{
    wstring sName;
    wstring sOwner;
    wstring sFullName;

    if(L'@' == sRawName[0] || L'[' == sRawName[0])
    {
        sName = sRawName;
    }
    else
    {
        sName.append(L"[");
        sName.append(sRawName);
        sName.append(L"]");
    }

    if(S_BLANK == sRawOwner)
    {
        sOwner = L"[dbo]";
    }
    else if(L'[' == sRawName[0])
    {
        sOwner = sRawName;
    }
    else
    {
        sOwner.append(L"[");
        sOwner.append(sRawName);
        sOwner.append(L"]");
    }

    if(L'@' == sRawName[0])
    {
        sFullName = sName;
    }
    else
    {
        sFullName = sOwner + L"." + sName;
    }

    return move(sFullName);
}

CSqlProcedure::CSqlProcedure()
    :m_sOwner(L"dbo")
{
}

CSqlProcedure::CSqlProcedure(const CSqlProcedure& that)
    :CSqlField(that)
    ,m_sOwner(that.m_sOwner)
    ,m_sName(that.m_sName)
    ,m_sReturnVariableName(that.m_sReturnVariableName)
    ,m_oArguments(that.m_oArguments)
{
}

CSqlProcedure::CSqlProcedure(const CSqlProcedure&& that)
{
    *this = move(that);
}

CSqlProcedure::~CSqlProcedure()
{
}

void CSqlProcedure::Owner(WSTRING& sOwner)
{
    if(L'[' == m_sOwner[0])
    {
        m_sOwner = m_sOwner.substr(1);

        if(L']' == m_sOwner[m_sOwner.length()-1])
        {
            m_sOwner = m_sOwner.substr(0, m_sOwner.length()-1);
        }
    }
    
    else
    {
        m_sOwner = sOwner;
    }
}

wstring CSqlProcedure::Owner()
{
    return m_sOwner;
}

void CSqlProcedure::Name(WSTRING& sName)
{
    if(L'[' == sName[0])
    {
        m_sName = sName.substr(1);

        if(L']' == m_sName[m_sName.length()-1])
        {
            m_sName = m_sName.substr(0, m_sName.length()-1);
        }
    }
    else
    {
        m_sName = sName;
    }
}

wstring CSqlProcedure::Name() const
{
    return m_sName;
}

void CSqlProcedure::ReturnVariableName(WSTRING& sReturnVariableName)
{
    m_sReturnVariableName = sReturnVariableName;
}

wstring CSqlProcedure::ReturnVariableName() const
{
   return m_sReturnVariableName;
}

void CSqlProcedure::AppendArgument(const CSqlArgument& oArgument)
{
    wstring sKey = UString::ToLower(oArgument.RightValue());

    m_oArguments.Append(sKey, oArgument);
}

CQueried<CSqlArgument> CSqlProcedure::QueryArgument(WSTRING& sName) const
{
    wstring sKey = UString::ToLower(sName);

    return m_oArguments.Query(sKey);
}

void CSqlProcedure::Clear()
{
    CSqlField::Clear();
    m_sOwner = L"dbo";
    m_sName = S_BLANK;
    m_sReturnVariableName = S_BLANK;
    m_oArguments.Clear();
}

wstring CSqlProcedure::ToFullName() const
{
    wstring sFullName;

    if(m_sName.length() > 0 && m_sOwner.length() > 0)
    {
        if(m_sName[0] != L'@')
        {
            sFullName.append(L"[");
            sFullName.append(m_sOwner);
            sFullName.append(L"].[");
            sFullName.append(m_sName);
            sFullName.append(L"]");
        }
        else
        {
            sFullName = m_sName; 
        }
    }

    return move(sFullName);
}

CCollection<wstring, CSqlArgument>& CSqlProcedure::QuoteArguments()
 {
     return m_oArguments;
 }

 const CSqlProcedure& CSqlProcedure::operator=(const CSqlProcedure& rvalue)
{
    CSqlField::operator=(rvalue);

    m_sOwner = rvalue.m_sOwner;
    m_sName = rvalue.m_sName;
    m_sReturnVariableName = rvalue.m_sReturnVariableName;
    m_oArguments = rvalue.m_oArguments;

    return *this;
}