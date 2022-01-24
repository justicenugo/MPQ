#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <stdexcept>
#include <iostream>
#include <vector>
#include <math.h>

/*
 * Binary Heap class
 */
template <typename T>
class BinaryHeap {
    public:
        void insert(const T& data)
        {
            elements.push_back(data);
            if(elements.size() > 1)
                up_heap(elements.size()-1);
        }
        bool is_empty() {return elements.empty();}
        T min() 
        {
            if (is_empty())
                throw ("empty queue");
            return elements.front();
        }
        T remove_min() 
        {
            if (is_empty())
                throw ("empty queue");
            T min = elements.front();
            if(elements.size()!= 2)
                swap(0, elements.size()-1);
            else
                min = elements.back();
            elements.pop_back();
            down_heap(0);
            return min;
        }
    private:
        std::vector<T> elements;
        int size = 0;
        void down_heap(int i);
        void up_heap(int i);

        //Pre-implemented helper functions
        void swap(int a, int b) { T c(elements[a]); elements[a] = elements[b]; elements[b] = c;}
        int right_child(int i) {return 2*i + 2;}
        int left_child(int i) {return 2*i + 1;}
        int parent(int i) {return floor((i-1)/2);}
        bool is_internal(int i) {return left_child(i) < size || right_child(i) < size;}
        bool is_leaf(int i) {return left_child(i) >= size && right_child(i) >= size;}
};

/*
 * Restores the binary heap property starting from a node that is smaller than its parent
 * O(log n)
 */
template <typename T>
void BinaryHeap<T>::up_heap(int i) {
    int parent_index = parent(i);
    /*
     * Can be computed iteratively or recursively
     */
    T temp;
    while (elements.at(i) < elements.at(parent(i)))
    {
        temp = elements.at(parent(i));
        elements.at(parent(i)) = elements.at(i);
        elements.at(i) = temp;
        i = parent(i);
    }
    /*
    if(i==0) {return;}
    if(elements[i] < elements[parent_index])
    {
        swap(i, parent_index);
        up_heap(parent_index);
    }*/

}

/*
 * Restores the binary heap property starting from an node that is larger than its children
 * O(log n)
 */
template <typename T>
void BinaryHeap<T>::down_heap(int i) {
    int right_index = right_child(i);
    int left_index = left_child(i);
    /*
     * Can be computed iteratively or recursively
     */
    /*
    if (left_index >= size || i >= size)
        return;
    T temp;
    if (right_index < size && ((elements.at(left_index) < elements.at(i)) || (elements.at(right_index) < elements.at(i))))
    {
        if (elements.at(left_index) < elements.at(right_index))
        {
            temp = elements.at(left_index);
            elements.at(left_index) = elements.at(i);
            elements.at(i) = temp;
            down_heap(left_index);
        }
        else if (elements.at(right_index) < elements.at(left_index))
        {
            temp = elements.at(right_index);
            elements.at(right_index) = elements.at(i);
            elements.at(i) = temp;
            down_heap(right_index);
        }
    }
    else if (elements.at(left_index) < elements.at(i))
    {
        temp = elements.at(left_index);
        elements.at(left_index) = elements.at(i);
        elements.at(i) = temp;
        down_heap(left_index);
    }*/
    if(i>=elements.size()||right_index>=elements.size()||left_index>=elements.size())
        return;
    if(elements[right_index] < elements[i])
    {
        swap(i, right_index);
        down_heap(right_index);
    }
    if(elements[left_index] < elements[i])
    {
        swap(i, left_index);
        down_heap(left_index);
    }
}
#endif