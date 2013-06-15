#ifndef SYTELINE_TECHNIQUE_SYSTEM_ECOTOPE_COLLECTION_H
#define SYTELINE_TECHNIQUE_SYSTEM_ECOTOPE_COLLECTION_H

#ifndef SYTELINE_SYSTEM_ECOTOPE_BASE_H
#include "Technique/Ecotope/Base.h"
#endif

namespace SyteLine { namespace Technique
{
    template<typename TClass>
    class SYTELINE_LIBRARY_EXPORT TQueried
    {
    protected:
        vector<TClass> m_gArray;

    public:
        TQueried()
        {
        }

        TQueried(const TQueried& that)
            :m_gArray(that.m_gArray)
        {
        }

        TQueried(const TQueried&& that)
        {
            *this = move(that);
        }

        virtual ~TQueried()
        {
        }

    public:
        bool Empty() const
        {
            return m_gArray.empty();
        }

        size_t Size() const
        {
            return m_gArray.size();
        }

        void Clear()
        {
            m_gArray.clear();
        }

        void Append(const TClass& tRecord)
        {
            m_gArray.push_back(tRecord);
        }

        TClass First() const
        {
            return m_gArray[0];
        }

        TClass Last() const
        {
            return m_gArray[m_gArray.size()-1];
        }

        TClass Get(size_t nIndex) const
        {
            return m_gArray[nIndex];
        }

    public:
        virtual const TQueried& operator=(const TQueried& rvalue)
        {
            m_gArray = rvalue.m_gArray;

            return *this;
        }

        virtual TClass operator[](size_t nIndex)
        {
            return Get(nIndex);
        }
    };

    template<typename TKey, typename TClass>
    class SYTELINE_LIBRARY_EXPORT TCollection
    {
    protected:
        vector<TClass> m_gCollection;
        map<TKey, size_t> m_gMapping;
        map<TKey, vector<size_t>> m_gCollision;

    public:
        TCollection()
        {
        }

        TCollection(const TCollection& that)
            :m_gCollection(that.m_gCollection)
            ,m_gMapping(that.m_gMapping)
            ,m_gCollision(that.m_gCollision)
        {
        }

        TCollection(const TCollection&& that)
        {
            *this = move(that);
        }

        virtual ~TCollection()
        {
        }

    public:
        void Append(const TKey& tKey, const TClass& tObject)
        {
            size_t nSubscript = m_gCollection.size();

            m_gCollection.push_back(tObject);
            m_gCollision[tKey].push_back(nSubscript);
            m_gMapping[tKey] = nSubscript;
        }

        TQueried<TClass> Query(const TKey& tKey) const
        {
            auto aCollision = m_gCollision.find(tKey);

            if(aCollision != m_gCollision.end())
            {
                TQueried<TClass> gResults;

                auto aVector = aCollision->second;

                for(int i = 0; i < aVector.size(); i++)
                {
                    gResults.Append(TClass(m_gCollection[aVector[i]]));
                }

                return move(gResults);
            }
            else
            {
                return move(TQueried<TClass>());
            }
        }

        TClass Last() const
        {
            return move(TClass(m_gCollection[m_gCollection.size()-1]));
        }

        TClass First() const
        {
            return move(TClass(m_gCollection[0]));
        }

        void Clear()
        {
            m_gCollection.clear();
            m_gMapping.clear();
        }

    public:
        virtual const TCollection& operator=(const TCollection& rvalue)
        {
            m_gCollection = rvalue.m_gCollection;
            m_gMapping = rvalue.m_gMapping;
            m_gCollision = rvalue.m_gCollision;

            return *this;
        }

        TQueried<TClass> operator[](const TKey& tKey)
        {
            return Query(tKey);
        }

        TClass operator[](size_t nIndex)
        {
            return m_gCollection[nIndex];
        }
    };
}}

#endif