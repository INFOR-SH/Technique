#ifndef SYTELINE_TECHNIQUE_CODE_SQLPROCEDURE_H
#define SYTELINE_TECHNIQUE_CODE_SQLPROCEDURE_H

#ifndef SYTELINE_TECHNIQUE_SYSTEM_ECOTOPE_ARRAY_H
#include "Technique/Ecotope/Array.h"
#endif
#ifndef SYTELINE_TECHNIQUE_CODE_SQLARGUMENT_H
#include "Technique/Code/SqlArgument.h"
#endif

namespace SyteLine { namespace Technique { namespace Code
{
    class SYTELINE_LIBRARY_EXPORT CSqlProcedure : public CSqlField
    {
    protected:
        mstring m_sName;
        mstring m_sReturnVariableName;
        CArray<mstring, CSqlArgument> m_oArguments;

    public:
        CSqlProcedure();
        CSqlProcedure(const CSqlProcedure& oThat);
        CSqlProcedure(const CSqlProcedure&& oThat);
        virtual ~CSqlProcedure();

    public:
        mstring Name() const;
        mstring ReturnVariableName() const;

        void Name(MSTRING& sName);
        void ReturnVariableName(MSTRING& sReturnVariableName);

        void AppendArgument(const CSqlArgument& oArgument);
        CSqlArgument QueryArgument(MSTRING& sName) const;
        CArray<mstring, CSqlArgument>& QuoteArguments();

    public:
        virtual void Clear();

    public:
        virtual const CSqlProcedure& operator=(const CSqlProcedure& oRValue);
    };
}}}

#endif
