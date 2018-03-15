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
    points.emplace_back(Graph<T1, T2>::point(50));
    points.emplace_back(Graph<T1, T2>::point(49));
    points.emplace_back(Graph<T1, T2>::point(44));
    points.emplace_back(Graph<T1, T2>::point(43));
    points.emplace_back(Graph<T1, T2>::point(45));
    points.emplace_back(Graph<T1, T2>::point(40));
    points.emplace_back(Graph<T1, T2>::point(40));
    points.emplace_back(Graph<T1, T2>::point(35));
    points.emplace_back(Graph<T1, T2>::point(3));
    points.emplace_back(Graph<T1, T2>::point(4));
    points.emplace_back(Graph<T1, T2>::point(6));
    points.emplace_back(Graph<T1, T2>::point(8));
    points.emplace_back(Graph<T1, T2>::point(9));
    points.emplace_back(Graph<T1, T2>::point(10));

    points[0].lines.emplace_back(Graph<T1, T2>::line(2, &points[2]));
    points[2].lines.emplace_back(Graph<T1, T2>::line(5, &points[4]));
    points[2].lines.emplace_back(Graph<T1, T2>::line(15, &points[5]));
}

template<class T1, class T2>
typename Graph<T1, T2>::iterator Graph<T1, T2>::getIterator(int id) {
    return Graph<T1, T2>::iterator(&points[id]);
}


#endif //GRAPH_GRAPH_H
