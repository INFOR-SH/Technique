#ifndef SYTELINE_TECHNIQUE_CODE_SQLDECLARATION_H
#define SYTELINE_TECHNIQUE_CODE_SQLDECLARATION_H

#ifndef SYTELINE_TECHNIQUE_SYSTEM_ECOTOPE_ARRAY_H
#include "Technique/Ecotope/Array.h"
#endif
#ifndef SYTELINE_TECHNIQUE_CODE_SQLVARIABLE_H
#include "Technique/Code/SqlVariable.h"
#endif

namespace SyteLine { namespace Technique { namespace Code
{
    class SYTELINE_LIBRARY_EXPORT CSqlDeclaration : public CSqlField
    {
    protected:
        mstring m_sName;
        mstring m_sReturnType;
        CArray<mstring, CSqlVariable> m_oParameters;

    public:
        CSqlDeclaration();
        CSqlDeclaration(const CSqlDeclaration& oThat);
        CSqlDeclaration(const CSqlDeclaration&& oThat);
        virtual ~CSqlDeclaration();

    public:
        mstring Name() const;
        mstring ReturnType() const;
        CArray<mstring, CSqlVariable> Parameters() const;

        void Name(MSTRING& sName);
        void ReturnType(MSTRING& sReturnType);
        void Parameters(const CArray<mstring, CSqlVariable>& stlParameters);
        void AppendParameter(const CSqlVariable& oParameter);
        CSqlVariable QueryParameter(MSTRING& sName) const;

        CArray<mstring, CSqlVariable>& QuoteParameters();

        mstring ToString(size_t nTabSize = 3);

    public:
        virtual const CSqlDeclaration& operator=(const CSqlDeclaration& oRValue);
    };
}}}

#endif