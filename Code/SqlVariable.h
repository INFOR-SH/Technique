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
        wstring m_sName;
        wstring m_sType;
        wstring m_sValue;
        bool m_bOutput;

    public:
        CSqlVariable();
        CSqlVariable(const CSqlVariable& that);
        CSqlVariable(const CSqlVariable&& that);
        virtual ~CSqlVariable();

    public:
        void Name(WSTRING& sName);
        wstring Name() const;
        void Type(WSTRING& sType);
        wstring Type() const;
        void Value(WSTRING& sValue);
        wstring Value() const;
        void Output(bool bOutput);
        bool Output() const;
    public:
        virtual void Clear();

    public:
        virtual const CSqlVariable& operator=(const CSqlVariable& rvalue);
    };
}}}

#endif
