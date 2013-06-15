#ifndef SYTELINE_TECHNIQUE_CODE_SQLFIELD_H
#define SYTELINE_TECHNIQUE_CODE_SQLFIELD_H

#ifndef SYTELINE_TECHNIQUE_SYSTEM_ECOTOPE_USAGE_H
#include "Technique/Ecotope/Usage.h"
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
        CSqlField(const CSqlField& that);
        CSqlField(const CSqlField&& that);
        virtual ~CSqlField();

    public:
        void StartingLine(size_t nLine);
        size_t StartingLine() const;
        void EndingLine(size_t nLine);
        size_t EndingLine() const;
    public:
        virtual void Clear();

    public:
        virtual const CSqlField& operator=(const CSqlField& rvalue);
    };
}}}


#endif