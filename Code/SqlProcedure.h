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
        //Owner and name have not '[' and ']'
        wstring m_sOwner;
        wstring m_sName;
        wstring m_sReturnVariableName;
        CCollection<wstring, CSqlArgument> m_oArguments;

    public:
        static wstring MakeFullName(WSTRING& sName, WSTRING& sOwner=S_BLANK);

    public:
        CSqlProcedure();
        CSqlProcedure(const CSqlProcedure& that);
        CSqlProcedure(const CSqlProcedure&& that);
        virtual ~CSqlProcedure();

    public:
        void Owner(WSTRING& sOwner);
        wstring Owner();
        void Name(WSTRING& sName);
        wstring Name() const;
        void ReturnVariableName(WSTRING& sReturnVariableName);
        wstring ReturnVariableName() const;

    public:
        virtual void AppendArgument(const CSqlArgument& oArgument);
        virtual CQueried<CSqlArgument> QueryArgument(WSTRING& sName) const;
    public:
        virtual void Clear();
        virtual wstring ToFullName() const;

    public:
        CCollection<wstring, CSqlArgument>& QuoteArguments();

    public:
        virtual const CSqlProcedure& operator=(const CSqlProcedure& rvalue);
    };
}}}

#endif
