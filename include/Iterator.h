//
// Created by user on 15.03.2018.
//

#ifndef GRAPH_ITERATOR_H
#define GRAPH_ITERATOR_H


#include "Graph.h"
#include <vector>


template <class T1, class T2>
class Graph;

template <class T1, class T2>
class Iterator {
public:
    typename Graph<T1, T2>::point* point;
    typename std::vector<typename Graph<T1, T2>::point>* points;

    explicit Iterator();
    explicit Iterator(typename Graph<T1, T2>::point* p, typename std::vector<typename Graph<T1, T2>::point>* ps);
    void next(int id);
    bool operator==(Iterator<T1, T2> it);
};

template<class T1, class T2>
void Iterator<T1, T2>::next(int id) {
    if (point->lines.size() > id) {
        point = point->lines[id].point;
    };
}

template<class T1, class T2>
Iterator<T1, T2>::Iterator() {
    point = nullptr;
    points = nullptr;
}

template<class T1, class T2>
Iterator<T1, T2>::Iterator(typename Graph<T1, T2>::point *p, typename std::vector<typename Graph<T1, T2>::point>* ps) {
    point = p;
    points = ps;
}

template<class T1, class T2>
bool Iterator<T1, T2>::operator==(Iterator<T1, T2> it) {
    return point->id == it.point->id;
}


#endif //GRAPH_ITERATOR_H
