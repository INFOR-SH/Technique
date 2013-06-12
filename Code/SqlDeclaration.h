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
        vector<CSqlVariable> m_stlParameters;
        map<mstring, size_t> m_stlParameterIndexs;

    public:
        CSqlDeclaration();
        CSqlDeclaration(const CSqlDeclaration& oThat);
        CSqlDeclaration(const CSqlDeclaration&& oThat);
        virtual ~CSqlDeclaration();

    public:
        mstring Name() const;
        mstring ReturnType() const;
        vector<CSqlVariable> Parameters() const;

        void Name(MSTRING& sName);
        void ReturnType(MSTRING& sReturnType);
        void Parameters(const vector<CSqlVariable>& stlParameters);
        void AddParameter(const CSqlVariable& oParameter);
        CSqlVariable GetParameter(MSTRING& sName) const;
        vector<CSqlVariable>& QuoteParameters();
        mstring ToString(size_t nTabSize = 3);

    public:
        virtual const CSqlDeclaration& operator=(const CSqlDeclaration& oRValue);
    };
}}}

#endif