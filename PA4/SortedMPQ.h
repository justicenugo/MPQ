#ifndef SORTEDMPQ_H
#define SORTEDMPQ_H

#include <stdexcept>
#include <list>
#include "MPQ.h"

/*
 * Minimum Priority Queue based on a linked list
 */
template <typename T>
class SortedMPQ: MPQ<T> {
    private:
        list<T> mpq;
    public:
    T remove_min()
    {
        if (is_empty())
            throw exception();
        T min_item = min();
        mpq.erase(mpq.begin());
        //mpq.pop_front();
        return min_item;
    }
    T min()
    {
        if (is_empty())
            throw exception();
        return mpq.front();
    }
    bool is_empty() {return mpq.empty();}
    void insert(const T& data)
    {
        /*for (typename list<T>::iterator i = mpq.begin(); i != mpq.end(); i++)
        {
            if (*i > data)
            {
                mpq.insert(i, data);
                break;
            }
        }*/
        //mpq.push_back(data);
        //mpq.sort();
        typename std::list<T>::iterator i;
        i = mpq.begin();
        while (i != mpq.end() && !(data < *i)) ++i;
        mpq.insert(i, data);
    }
};

#endif