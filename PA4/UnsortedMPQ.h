#ifndef UNSORTEDMPQ_H
#define UNSORTEDMPQ_H

#include <stdexcept>
#include <vector>
#include "MPQ.h"

/*
 * Minimum Priority Queue based on a vector
 */
template <typename T>
class UnsortedMPQ: MPQ<T> {
    private:
        vector<T> mpq;
    public:
        T remove_min()
        {
            if (is_empty())
                throw ("empty queue");
            T min_item = mpq.front();
            typename vector<T>::iterator it = mpq.begin();
            typename vector<T>::iterator indx = mpq.begin();
            for(; it != mpq.end(); it++)
            {
                if(*it < min_item) {
                    min_item = *it;
                    indx = it;
                }
            }
            mpq.erase(indx);
            return min_item;
        }
        T min()
        {
            if (is_empty())
                throw ("empty queue");
            T min_item = mpq.front();
            for(auto i : mpq)
            {
                if(i < min_item) {
                    min_item = i;
                }
            }
            return min_item;
        }
        bool is_empty() {return mpq.empty();}
        void insert(const T& data) {mpq.push_back(data);}
};

#endif