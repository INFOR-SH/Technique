#ifndef SYTELINE_TECHNIQUE_CODE_SQLDECLARATION_H
#define SYTELINE_TECHNIQUE_CODE_SQLDECLARATION_H

#ifndef SYTELINE_TECHNIQUE_CODE_SQLFIELD_H
#include "Technique/Code/SqlField.h"
#endif
#ifndef SYTELINE_TECHNIQUE_CODE_SQLVARIABLE_H
#include "Technique/Code/SqlVariable.h"
#endif

namespace SyteLine { namespace Technique { namespace Code
{
    class SYTELINE_LIBRARY_EXPORT CSqlDeclaration : public CSqlField
    {
    protected:
        wstring m_sName;
        wstring m_sReturnType;
        CCollection<wstring, CSqlVariable> m_oParameters;

    public:
        CSqlDeclaration();
        CSqlDeclaration(const CSqlDeclaration& that);
        CSqlDeclaration(const CSqlDeclaration&& that);
        virtual ~CSqlDeclaration();

    public:
        void Name(WSTRING& sName);
        wstring Name() const;
        void ReturnType(WSTRING& sReturnType);
        wstring ReturnType() const;
        void Parameters(const CCollection<wstring, CSqlVariable>& gParameters);
        CCollection<wstring, CSqlVariable> Parameters() const;
    public:
        void AppendParameter(const CSqlVariable& oParameter);
        CQueried<CSqlVariable> QueryParameter(WSTRING& sName) const;
        wstring ToString(size_t nTabSize = 3);
    public:
        CCollection<wstring, CSqlVariable>& QuoteParameters();

    public:
        virtual const CSqlDeclaration& operator=(const CSqlDeclaration& rvalue);
    };
}}}

#endif