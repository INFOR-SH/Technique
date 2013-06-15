#ifndef SYTELINE_TECHNIQUE_SYSTEM_ECOTOPE_ARRAY_H
#define SYTELINE_TECHNIQUE_SYSTEM_ECOTOPE_ARRAY_H

#ifndef SYTELINE_SYSTEM_ECOTOPE_BASE_H
#include "Technique/Ecotope/Base.h"
#endif

namespace SyteLine { namespace Technique
{
    template<typename TKey, typename TClass>
    class CArray
    {
    protected:
        vector<TClass> m_stlArray;
        map<TKey, size_t> m_stlMapping;
        map<TKey, vector<size_t>> m_stlCollision;

    public:
        CArray()
        {
        }

        CArray(const CArray& oThat)
            :m_stlArray(oThat.m_stlArray)
            ,m_stlMapping(oThat.m_stlMapping)
            ,m_stlCollision(oThat.m_stlCollision)
        {
        }

        CArray(const CArray&& oThat)
        {
            *this = move(oThat);
        }

        virtual ~CArray()
        {
        }

    public:
        void Append(const TKey& tKey, const TClass& tObject)
        {
            m_stlArray.push_back(tObject);

            size_t nIndex = m_stlArray.size() - 1;

            m_stlCollision[tKey].push_back(nIndex);
            m_stlMapping[tKey] = nIndex;
        }

        TClass Query(const TKey& tKey) const
        {
            /*auto a = m_stlMapping.find(tKey);

            if(a != m_stlMapping.end())
            {
                return move(TClass(m_stlArray[a->second]));
            }
            else
            {
                return TClass();
            }*/
            auto aCollision = m_stlCollision.find(tKey);

            if(aCollision != m_stlCollision.end())
            {
                vector<size_t> stlVector = aCollision->second;

                for(int i = 0; i < stlVector.size(); i++)
                {
                    return move(TClass(m_stlArray[stlVector[i]]));
                }
            }
            else
            {
                return move(TClass());
            }
        }

        TClass Last() const
        {
            return move(TClass(m_stlArray[m_stlArray.size()-1]));
        }

        TClass First() const
        {
            return move(TClass(m_stlArray[0]));
        }

        void Clear()
        {
            m_stlArray.clear();
            m_stlMapping.clear();
        }

    public:
        virtual const CArray& operator=(const CArray& oRValue)
        {
            m_stlArray = oRValue.m_stlArray;
            m_stlMapping = oRValue.m_stlMapping;
            m_stlCollision = oRValue.m_stlCollision;

            return *this;
        }

        TClass operator[](const TKey& tKey)
        {
            return Query(tKey);
        }

        TClass operator[](size_t nIndex)
        {
            return m_stlArray[nIndex];
        }
    };
}}

#endif