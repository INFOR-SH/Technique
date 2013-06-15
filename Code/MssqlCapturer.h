#ifndef SYTELINE_TECHNIQUE_CODE_MSSQLCAPTURER_H
#define SYTELINE_TECHNIQUE_CODE_MSSQLCAPTURER_H

#ifndef SYTELINE_TECHNIQUE_CODE_CAPTURER_H
#include "Technique/Code/Capturer.h"
#endif
#ifndef SYTELINE_TECHNIQUE_CODE_SQLFIE_H
#include "Technique/Code/SqlFile.h"
#endif
#ifndef SYTELINE_TECHNIQUE_CODE_SQLDECLARATION_H
#include "Technique/Code/SqlDeclaration.h"
#endif
#ifndef SYTELINE_TECHNIQUE_CODE_SQLPROCEDURE_H
#include "Technique/Code/SqlProcedure.h"
#endif
#ifndef SYTELINE_TECHNIQUE_CODE_SQLVARIABLE_H
#include "Technique/Code/SqlVariable.h"
#endif

namespace SyteLine { namespace Technique { namespace Code
{
    class SYTELINE_LIBRARY_EXPORT CMssqlCapturer : public CCapturer
    {
    protected:
        CSqlFile m_oSqlFile;

    public:
        CMssqlCapturer();
        CMssqlCapturer(const CMssqlCapturer& that);
        virtual ~CMssqlCapturer();

    public:
        virtual void CaptureDeclaration(const CSqlDeclaration& oDeclaration);
        virtual void CaptureProcedure(const CSqlProcedure& oProcedure);
        virtual void CaptureVariable(const CSqlVariable& oVariable);
        virtual TQueried<CSqlVariable> QueryParameter(WSTRING& sName) const;
        virtual TQueried<CSqlProcedure> QueryProcedure(WSTRING& sName) const;

    public:
        const CSqlFile& QuoteSqlFile() const;

    public:
        virtual const CMssqlCapturer& operator=(const CMssqlCapturer& rvalue);
    };
}}}

#endif
