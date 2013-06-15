#ifndef SYTELINE_TECHNIQUE_CODE_MSSQLCAPTURER_H
#define SYTELINE_TECHNIQUE_CODE_MSSQLCAPTURER_H

#ifndef SYTELINE_TECHNIQUE_CODE_CAPTURER_H
#include "Technique/Code/Capturer.h"
#endif
#ifndef SYTELINE_TECHNIQUE_CODE_SQLFIE_H
#include "Technique/Code/SqlFile.h"
#endif

namespace SyteLine { namespace Technique { namespace Code
{
    class CSqlDeclaration;
    class CSqlProcedure;

    class SYTELINE_LIBRARY_EXPORT CMssqlCapturer : public CCapturer
    {
    protected:
        CSqlFile m_oSqlFile;

    public:
        CMssqlCapturer();
        CMssqlCapturer(const CMssqlCapturer& oThat);
        virtual ~CMssqlCapturer();

    public:
        virtual void CaptureDeclaration(const CSqlDeclaration& oDeclaration);
        virtual void CaptureProcedure(const CSqlProcedure& oProcedure);
        virtual void CaptureVariable(const CSqlVariable& oVariable);
        virtual CSqlVariable QueryParameter(MSTRING& sName) const;
        virtual CSqlProcedure QueryProcedure(MSTRING& sName) const;

    public:
        CSqlFile GetSqlFile() const;

    public:
        virtual const CMssqlCapturer& operator=(const CMssqlCapturer& oRValue);
    };
}}}

#endif
