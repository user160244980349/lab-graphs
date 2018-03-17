//
// Created by user on 15.03.2018.
//

#ifndef GRAPH_POINT_H
#define GRAPH_POINT_H


#include "Graph.h"
#include "Line.h"
#include <vector>


template <class T1, class T2>
class Graph;

template <class T1, class T2>
class Point {
public:
    static int count;
    int id;
    T1 data;
    std::vector<typename Graph<T1, T2>::line> lines;

    explicit Point(T1 d);
};

template<class T1, class T2>
Point<T1, T2>::Point(T1 d) {
    data = d;
    id = count++;
}

template <class T1, class T2>
int Point<T1, T2>::count = 0;


#endif //GRAPH_POINT_H
