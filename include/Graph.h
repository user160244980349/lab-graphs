//
// Created by user on 15.03.2018.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H


#include "Point.h"
#include "Iterator.h"
#include "Line.h"


template <class T1, class T2>
class Iterator;
template <class T1, class T2>
class Point;
template <class T1, class T2>
class Line;

template <class T1, class T2>
class Graph {
public:
    typedef Iterator<T1, T2> iterator;
    typedef Point<T1, T2> point;
    typedef Line<T1, T2> line;

    std::vector<Graph<T1, T2>::point> points;

    explicit Graph(std::vector<typename Graph<T1, T2>::point> p);
    Graph<T1, T2>::iterator getIterator(int id);
};

template<class T1, class T2>
Graph<T1, T2>::Graph(std::vector<typename Graph<T1, T2>::point> p) {
    points = p;
}

template<class T1, class T2>
typename Graph<T1, T2>::iterator Graph<T1, T2>::getIterator(int id) {
    return Graph<T1, T2>::iterator(&points[id], &points);
}


#endif //GRAPH_GRAPH_H
