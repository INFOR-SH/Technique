#ifndef SYTELINE_TECHNIQUE_CODE_MSSQLDRIVER_H
#define SYTELINE_TECHNIQUE_CODE_MSSQLDRIVER_H

#ifndef SYTELINE_TECHNIQUE_CODE_FILEDRIVER_H
#include "Technique/Code/FileDriver.h"
#endif
#ifndef SYTELINE_TECHNIQUE_CODE_SQLFIE_H
#include "Technique/Code/SqlFile.h"
#endif

namespace SyteLine { namespace Technique { namespace Code
{
    class CSqlDeclaration;
    class CSqlProcedure;

    class SYTELINE_LIBRARY_EXPORT CMssqlDriver : public CFileDriver
    {
    protected:
        CSqlFile m_oSqlFile;

    public:
        CMssqlDriver();
        CMssqlDriver(const CMssqlDriver& oThat);
        virtual ~CMssqlDriver();

    public:
        virtual void Declaration(const CSqlDeclaration& oDeclaration);
        virtual void Procedure(const CSqlProcedure& oProcedure);
        virtual void Variable(const CSqlVariable& oVariable);
        virtual CSqlVariable QueryParameter(MSTRING& sName);

    public:
        CSqlFile GetSqlFile() const;

    public:
        virtual const CMssqlDriver& operator=(const CMssqlDriver& oRValue);
    };
}}}

#endif
