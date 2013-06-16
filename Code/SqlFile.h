#ifndef SYTELINE_TECHNIQUE_CODE_SQLFIE_H
#define SYTELINE_TECHNIQUE_CODE_SQLFIE_H

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
        CCollection<wstring, CSqlProcedure> m_oProcedures;

    public:
        CSqlFile();
        CSqlFile(const CSqlFile& that);
        CSqlFile(const CSqlFile&& that);
        virtual ~CSqlFile();

    public:
        void Declaration(const CSqlDeclaration& oDeclaration);
        CSqlDeclaration Declaration() const;
        void Procedures(const CCollection<wstring, CSqlProcedure>& oProcedures);
        CCollection<wstring, CSqlProcedure> Procedures() const;
    public:
        void AppendProcedure(const CSqlProcedure& oProcedure); 
        CQueried<CSqlVariable> QueryParameter(WSTRING& sName) const;
        CQueried<CSqlProcedure> QueryProcedure(WSTRING& sName) const;
    public:
        CSqlDeclaration& QuoteDeclaration();
        CCollection<wstring, CSqlProcedure>& QuoteProcedures();

    public:
        const CSqlFile& operator=(const CSqlFile& rvalue);
        
    };
}}}

#endif
