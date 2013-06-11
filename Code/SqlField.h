#ifndef SYTELINE_TECHNIQUE_CODE_SQLFIELD_H
#define SYTELINE_TECHNIQUE_CODE_SQLFIELD_H

#ifndef SYTELINE_TECHNIQUE_SYSTEM_ECOTOPE_BASE_H
#include "Technique/Ecotope/Base.h"
#endif

namespace SyteLine { namespace Technique { namespace Code
{
    class SYTELINE_LIBRARY_EXPORT CSqlField
    {
    protected:
        size_t m_nStartingLine;
        size_t m_nEndingLine;

    public:
        CSqlField();
        CSqlField(const CSqlField& oThat);
        CSqlField(const CSqlField&& oThat);
        virtual ~CSqlField();

    public:
        size_t StartingLine() const;
        size_t EndingLine() const;
        void StartingLine(size_t nLine);
        void EndingLine(size_t nLine);

        virtual void Clear();

    public:
        virtual const CSqlField& operator=(const CSqlField& oRValue);
    };
}}}


#endif