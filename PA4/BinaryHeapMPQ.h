#ifndef BINARYHEAP_MPQ_H
#define BINARYHEAP_MPQ_H

#include "BinaryHeap.h"
#include <stdexcept>
#include "MPQ.h"

/*
 * Minimum Priority Queue based on a binary heap
 */
template <typename T>
class BinaryHeapMPQ: MPQ<T> {
    private:
        BinaryHeap<T> mpq;
    public:
        virtual T remove_min()
        {
            return mpq.remove_min();
        }
        virtual T min()
        {
            return mpq.min();
        }
        virtual bool is_empty()
        {
            return mpq.is_empty();
        }
        virtual void insert(const T& data)
        {
            mpq.insert(data);
        }

};

#endif