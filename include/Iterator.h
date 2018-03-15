//
// Created by user on 15.03.2018.
//

#ifndef GRAPH_ITERATOR_H
#define GRAPH_ITERATOR_H


#include "Graph.h"
#include <vector>
#include <iostream>


template <class T1, class T2>
class Graph;

template <class T1, class T2>
class Iterator {
public:
    typename Graph<T1, T2>::point* point;
    T1 pointWeight;
    T2 lineWeight;

    explicit Iterator(typename Graph<T1, T2>::point* p);
    void move(int id);
};

template<class T1, class T2>
void Iterator<T1, T2>::move(int id) {
    if (point->lines[id].point != nullptr) {
        lineWeight = point->lines[id].data;
        point = point->lines[id].point;
        pointWeight = point->data;
    } else
        std::cout << "Point is undefined" << std::endl;
}

template<class T1, class T2>
Iterator<T1, T2>::Iterator(typename Graph<T1, T2>::point *p) {
    point = p;
    pointWeight = point->data;
    lineWeight = 0;
}


#endif //GRAPH_ITERATOR_H
