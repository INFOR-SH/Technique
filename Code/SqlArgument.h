#ifndef SYTELINE_TECHNIQUE_CODE_SQLARGUMENT_H
#define SYTELINE_TECHNIQUE_CODE_SQLARGUMENT_H

#ifndef SYTELINE_TECHNIQUE_CODE_SQLFIELD_H
#include "Technique/Code/SqlField.h"
#endif

namespace SyteLine { namespace Technique { namespace Code
{ 
    class SYTELINE_LIBRARY_EXPORT CSqlArgument : public CSqlField
    {
    protected:
        wstring m_sLeftValue;
        wstring m_sRightValue;
        bool m_bOutput;

    public:
        CSqlArgument();
        CSqlArgument(const CSqlArgument& that);
        CSqlArgument(const CSqlArgument&& that);
        virtual ~CSqlArgument();

    public:
        void LeftValue(WSTRING& sValue);
        wstring LeftValue() const;
        void RightValue(WSTRING& sValue);
        wstring RightValue() const;
        void Output(bool bOutput);
        bool Output() const;

    public:
        virtual void Clear();

    public:
        const CSqlArgument& operator=(const CSqlArgument& rvalue);
    };
}}}

#endif