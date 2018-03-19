#include <Graph.h>
#include <list>
#include <algorithm>
#include <map>
#include <iostream>
#include <PointData.h>


void aStar(Graph<PointData, int>::iterator start, Graph<PointData, int>::iterator finish);
void formic(Graph<PointData, int>::iterator start, Graph<PointData, int>::iterator finish);

int main() {

    std::vector<typename Graph<PointData, int>::point> points;

    points.emplace_back(Graph<PointData, int>::point({0,0,0}));
    points.emplace_back(Graph<PointData, int>::point({10,0,0}));
    points.emplace_back(Graph<PointData, int>::point({9,0,0}));
    points.emplace_back(Graph<PointData, int>::point({6,0,0}));
    points.emplace_back(Graph<PointData, int>::point({7,0,0}));
    points.emplace_back(Graph<PointData, int>::point({0,0,0}));

    points[0].lines.emplace_back(Graph<PointData, int>::line(5, &points[1]));
    points[0].lines.emplace_back(Graph<PointData, int>::line(2, &points[2]));
    points[1].lines.emplace_back(Graph<PointData, int>::line(10, &points[5]));
    points[2].lines.emplace_back(Graph<PointData, int>::line(3, &points[3]));
    points[2].lines.emplace_back(Graph<PointData, int>::line(2, &points[4]));
    points[3].lines.emplace_back(Graph<PointData, int>::line(4, &points[5]));
    points[4].lines.emplace_back(Graph<PointData, int>::line(9, &points[5]));

    Graph<PointData, int> graph = points;

    Graph<PointData, int>::iterator start = graph.getIterator(0);
    Graph<PointData, int>::iterator finish = graph.getIterator(5);
    aStar(start, finish);

    return 0;
}

void aStar(Graph<PointData, int>::iterator start, Graph<PointData, int>::iterator finish) {

    std::list<typename Graph<PointData, int>::iterator> openedPoints;
    std::list<typename Graph<PointData, int>::iterator> closedPoints;

    openedPoints.emplace_back(start);

    std::cout << std::endl;
    std::cout << "[start] at " << start.point->id << std::endl;
    std::cout << "[finish] at " << finish.point->id << std::endl;
    std::cout << std::endl;

    while (!openedPoints.empty()) {

        Graph<PointData, int>::iterator parent = openedPoints.front();

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
            Graph<PointData, int>::iterator child = parent;
            child.next(i);

            auto uIterator = std::find(closedPoints.begin(), closedPoints.end(), child);
            auto qIterator = std::find(openedPoints.begin(), openedPoints.end(), child);

            if (uIterator == closedPoints.end()) {
                child.point->data.wayWeight = parent.point->data.wayWeight + parent.point->lines[i].data;
                child.point->data.heuristic = child.point->data.wayWeight + child.point->data.weight;
                std::cout << "checking at " << child.point->id << " and heuristic is " << child.point->data.heuristic << std::endl;

                if (qIterator == openedPoints.end())
                    openedPoints.emplace_back(child);
            }
        }
        std::cout << std::endl;
    }
}

void formic() {



}