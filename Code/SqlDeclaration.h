#ifndef SYTELINE_TECHNIQUE_CODE_SQLDECLARATION_H
#define SYTELINE_TECHNIQUE_CODE_SQLDECLARATION_H

#ifndef SYTELINE_TECHNIQUE_CODE_SQLFIELD_H
#include "Technique/Code/SqlField.h"
#endif

namespace SyteLine { namespace Technique { namespace Code
{
    class CSqlVariable;

    class SYTELINE_LIBRARY_EXPORT CSqlDeclaration : public CSqlField
    {
    protected:
        mstring m_sName;
        mstring m_sReturnType;
        map<mstring, CSqlVariable> m_stlParameters;

    public:
        CSqlDeclaration();
        CSqlDeclaration(const CSqlDeclaration& oThat);
        CSqlDeclaration(const CSqlDeclaration&& oThat);
        virtual ~CSqlDeclaration();

    public:
        mstring Name() const;
        mstring ReturnType() const;
        map<mstring, CSqlVariable> Parameters() const;

        void Name(MSTRING& sName);
        void ReturnType(MSTRING& sReturnType);
        void Parameters(const map<mstring, CSqlVariable>& stlParameters);
        void AddParameter(const CSqlVariable& oParameter);
        CSqlVariable GetParameter(MSTRING& sName) const;
        map<mstring, CSqlVariable>& QuoteParameters();
        mstring ToString(size_t nTabSize = 3);

    public:
        virtual const CSqlDeclaration& operator=(const CSqlDeclaration& oRValue);
    };
}}}

#endif