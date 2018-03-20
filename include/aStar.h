//
// Created by user on 20.03.2018.
//

#ifndef GRAPH_ASTAR_H
#define GRAPH_ASTAR_H


#include "PointData.h"
#include "LineData.h"
#include "Graph.h"


void aStar(Graph<PointData, LineData>::iterator start, Graph<PointData, LineData>::iterator finish);


#endif //GRAPH_ASTAR_H
