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
        mstring m_sLeftValue;
        mstring m_sRightValue;
        bool m_bOutput;

    public:
        CSqlArgument();
        CSqlArgument(const CSqlArgument& oThat);
        CSqlArgument(const CSqlArgument&& oThat);
        virtual ~CSqlArgument();

    public:
        mstring LeftValue() const;
        mstring RightValue() const;
        bool Output() const;
        void LeftValue(MSTRING& sValue);
        void RightValue(MSTRING& sValue);
        void Output(bool bOutput);

    public:
        virtual void Clear();

    public:
        const CSqlArgument& operator=(const CSqlArgument& oRValue);
    };
}}}

#endif