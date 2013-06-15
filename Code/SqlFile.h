#ifndef SYTELINE_TECHNIQUE_CODE_SQLFIE_H
#define SYTELINE_TECHNIQUE_CODE_SQLFIE_H

#ifndef SYTELINE_TECHNIQUE_SYSTEM_ECOTOPE_ARRAY_H
#include "Technique/Ecotope/Array.h"
#endif
#ifndef SYTELINE_TECHNIQUE_CODE_SQLDECLARATION_H
#include "Technique/Code/SqlDeclaration.h"
#endif
#ifndef SYTELINE_TECHNIQUE_CODE_SQLPROCEDURE_H
#include "Technique/Code/SqlProcedure.h"
#endif

namespace SyteLine { namespace Technique { namespace Code
{
    class SYTELINE_LIBRARY_EXPORT CSqlFile
    {
    protected:
        CSqlDeclaration m_oDeclaration;
        CArray<mstring, CSqlProcedure> m_oProcedures;

    public:
        CSqlFile();
        CSqlFile(const CSqlFile& oThat);
        CSqlFile(const CSqlFile&& oThat);
        virtual ~CSqlFile();

    public:
        void Declaration(const CSqlDeclaration& oDeclaration); 
        void AppendProcedure(const CSqlProcedure& oProcedure); 
        CSqlDeclaration Declaration() const;
        CArray<mstring, CSqlProcedure> Procedures() const;
        CSqlVariable QueryParameter(MSTRING& sName) const;
        CSqlProcedure QueryProcedure(MSTRING& sName) const;
    public:
        CSqlDeclaration& QuoteDeclaration();
        CArray<mstring, CSqlProcedure>& QuoteProcedures();

    public:
        const CSqlFile& operator=(const CSqlFile& oRValue);
        
    };
}}}

#endif
