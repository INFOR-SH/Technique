#ifndef SYTELINE_TECHNIQUE_CODE_SQLPROCEDURE_H
#define SYTELINE_TECHNIQUE_CODE_SQLPROCEDURE_H

#ifndef SYTELINE_TECHNIQUE_CODE_SQLFIELD_H
#include "Technique/Code/SqlField.h"
#endif
#ifndef SYTELINE_TECHNIQUE_CODE_SQLARGUMENT_H
#include "Technique/Code/SqlArgument.h"
#endif

namespace SyteLine { namespace Technique { namespace Code
{
    class SYTELINE_LIBRARY_EXPORT CSqlProcedure : public CSqlField
    {
    protected:
        wstring m_sName;
        wstring m_sReturnVariableName;
        TCollection<wstring, CSqlArgument> m_oArguments;

    public:
        CSqlProcedure();
        CSqlProcedure(const CSqlProcedure& that);
        CSqlProcedure(const CSqlProcedure&& that);
        virtual ~CSqlProcedure();

    public:
        void Name(WSTRING& sName);
        wstring Name() const;
        void ReturnVariableName(WSTRING& sReturnVariableName);
        wstring ReturnVariableName() const;
    public:
        void AppendArgument(const CSqlArgument& oArgument);
        TQueried<CSqlArgument> QueryArgument(WSTRING& sName) const;
    public:
        virtual void Clear();

    public:
        TCollection<wstring, CSqlArgument>& QuoteArguments();

    public:
        virtual const CSqlProcedure& operator=(const CSqlProcedure& rvalue);
    };
}}}

#endif
