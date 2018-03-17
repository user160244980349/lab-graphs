//
// Created by user on 15.03.2018.
//

#ifndef GRAPH_LINE_H
#define GRAPH_LINE_H


#include "Graph.h"
#include <vector>


template <class T1, class T2>
class Graph;

template <class T1, class T2>
class Line {
public:
    T2 data;
    typename Graph<T1, T2>::point* point;

    Line(T2 d, typename Graph<T1, T2>::point* p);
};

template<class T1, class T2>
Line<T1, T2>::Line(T2 d, typename Graph<T1, T2>::point *p) {
    data = d;
    point = p;
}


#endif //GRAPH_LINE_H
