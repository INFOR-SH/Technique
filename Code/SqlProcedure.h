#ifndef SYTELINE_TECHNIQUE_CODE_SQLPROCEDURE_H
#define SYTELINE_TECHNIQUE_CODE_SQLPROCEDURE_H

#ifndef SYTELINE_TECHNIQUE_CODE_SQLFIELD_H
#include "Technique/Code/SqlField.h"
#endif

namespace SyteLine { namespace Technique { namespace Code
{
    class CSqlArgument;

    class SYTELINE_LIBRARY_EXPORT CSqlProcedure : public CSqlField
    {
    protected:
        mstring m_sName;
        mstring m_sReturnValue;
        vector<CSqlArgument> m_stlArguments;

    public:
        CSqlProcedure();
        CSqlProcedure(const CSqlProcedure& oThat);
        CSqlProcedure(const CSqlProcedure&& oThat);
        virtual ~CSqlProcedure();

    public:
        mstring Name() const;
        mstring ReturnValue() const;
        void Name(MSTRING& sName);
        void ReturnValue(MSTRING& sReturnValue);
        void AppendArgument(const CSqlArgument& oArgument);
        vector<CSqlArgument>& QuoteArguments();
    public:
        virtual void Clear();

    public:
        virtual const CSqlProcedure& operator=(const CSqlProcedure& oRValue);
    };
}}}

#endif
