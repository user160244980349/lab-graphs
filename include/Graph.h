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

    Graph();
    Graph<T1, T2>::iterator getIterator(int id);
};

template<class T1, class T2>
Graph<T1, T2>::Graph() {
    points.emplace_back(Graph<T1, T2>::point({0,0,0}));
    points.emplace_back(Graph<T1, T2>::point({10,0,0}));
    points.emplace_back(Graph<T1, T2>::point({19,0,0}));
    points.emplace_back(Graph<T1, T2>::point({6,0,0}));
    points.emplace_back(Graph<T1, T2>::point({7,0,0}));
    points.emplace_back(Graph<T1, T2>::point({0,0,0}));

    points[0].lines.emplace_back(Graph<T1, T2>::line(5, &points[1]));
    points[0].lines.emplace_back(Graph<T1, T2>::line(2, &points[2]));
    points[1].lines.emplace_back(Graph<T1, T2>::line(10, &points[5]));
    points[2].lines.emplace_back(Graph<T1, T2>::line(3, &points[3]));
    points[2].lines.emplace_back(Graph<T1, T2>::line(2, &points[4]));
    points[3].lines.emplace_back(Graph<T1, T2>::line(4, &points[5]));
    points[4].lines.emplace_back(Graph<T1, T2>::line(9, &points[5]));
}

template<class T1, class T2>
typename Graph<T1, T2>::iterator Graph<T1, T2>::getIterator(int id) {
    return Graph<T1, T2>::iterator(&points[id]);
}


#endif //GRAPH_GRAPH_H
