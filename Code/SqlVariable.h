#ifndef SYTELINE_TECHNIQUE_CODE_SQLVARIABLE_H
#define SYTELINE_TECHNIQUE_CODE_SQLVARIABLE_H

#ifndef SYTELINE_TECHNIQUE_CODE_SQLFIELD_H
#include "Technique/Code/SqlField.h"
#endif

namespace SyteLine { namespace Technique { namespace Code
{ 
    class SYTELINE_LIBRARY_EXPORT CSqlVariable : public CSqlField
    {
    protected:
        mstring m_sName;
        mstring m_sType;
        mstring m_sValue;
        bool m_bOutput;

    public:
        CSqlVariable();
        CSqlVariable(const CSqlVariable& oThat);
        CSqlVariable(const CSqlVariable&& oThat);
        virtual ~CSqlVariable();

    public:
        mstring Name() const;
        mstring Type() const;
        mstring Value() const;
        bool Output() const;
        void Name(MSTRING& sName);
        void Type(MSTRING& sType);
        void Value(MSTRING& sValue);
        void Output(bool bOutput);
    public:
        virtual void Clear();

    public:
        virtual const CSqlVariable& operator=(const CSqlVariable& oRValue);
    };
}}}

#endif
