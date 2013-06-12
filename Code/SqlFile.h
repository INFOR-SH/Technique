#ifndef SYTELINE_TECHNIQUE_CODE_SQLFIE_H
#define SYTELINE_TECHNIQUE_CODE_SQLFIE_H

#ifndef SYTELINE_TECHNIQUE_CODE_SQLDECLARATION_H
#include "Technique/Code/SqlDeclaration.h"
#endif

namespace SyteLine { namespace Technique { namespace Code
{
    class CSqlProcedure;

    class SYTELINE_LIBRARY_EXPORT CSqlFile
    {
    protected:
        CSqlDeclaration m_oDeclaration;
        vector<CSqlProcedure> m_stlProcedures;
        map<mstring, size_t> m_stlProcedureIndexs;

    public:
        CSqlFile();
        CSqlFile(const CSqlFile& oThat);
        CSqlFile(const CSqlFile&& oThat);
        virtual ~CSqlFile();

    public:
        void Declaration(const CSqlDeclaration& oDeclaration); 
        void AddProcedure(const CSqlProcedure& oProcedure); 
        CSqlDeclaration Declaration() const;
        vector<CSqlProcedure> Procedures() const;
        CSqlProcedure GetProcedure(MSTRING& sName) const;
        CSqlDeclaration& QuoteDeclaration();
        vector<CSqlProcedure>& QuoteProcedures();

    public:
        const CSqlFile& operator=(const CSqlFile& oRValue);
        
    };
}}}

#endif
