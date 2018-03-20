//
// Created by user on 20.03.2018.
//

#include <iostream>
#include <list>
#include "aStar.h"
#include <algorithm>

void aStar(Graph<PointData, LineData>::iterator start, Graph<PointData, LineData>::iterator finish) {

    std::list<typename Graph<PointData, LineData>::iterator> openedPoints;
    std::list<typename Graph<PointData, LineData>::iterator> closedPoints;

    openedPoints.emplace_back(start);

    std::cout << std::endl;
    std::cout << "[start] at " << start.point->id << std::endl;
    std::cout << "[finish] at " << finish.point->id << std::endl;
    std::cout << std::endl;

    while (!openedPoints.empty()) {

        Graph<PointData, LineData>::iterator parent = openedPoints.front();

        for (auto p : openedPoints)
            if (p.point->data.heuristic < parent.point->data.heuristic)
                parent = p;

        if (parent == finish) {
            std::cout << "way found! Total range is " << parent.point->data.wayWeight << std::endl;
            return;
        }

        std::cout << "opened points [ ";
        for (auto p : openedPoints)
            std::cout << p.point->id << " ";
        std::cout << "]" << std::endl;

        std::cout << "closed points [ ";
        for (auto p : closedPoints)
            std::cout << p.point->id << " ";
        std::cout << "]" << std::endl;

        std::cout << "standing at " << parent.point->id << std::endl;

        closedPoints.emplace_back(parent);
        openedPoints.remove(parent);

        for (int i = 0; i < parent.point->lines.size(); i++) {
            Graph<PointData, LineData>::iterator child = parent;
            child.next(i);

            auto uIterator = std::find(closedPoints.begin(), closedPoints.end(), child);
            auto qIterator = std::find(openedPoints.begin(), openedPoints.end(), child);

            if (uIterator == closedPoints.end()) {
                child.point->data.wayWeight = parent.point->data.wayWeight + parent.point->lines[i].data.weight;
                child.point->data.heuristic = child.point->data.wayWeight + child.point->data.weight;
                std::cout << "checking at " << child.point->id << " and heuristic is " << child.point->data.heuristic << std::endl;

                if (qIterator == openedPoints.end())
                    openedPoints.emplace_back(child);
            }
        }
        std::cout << std::endl;
    }
}
