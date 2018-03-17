#include <Graph.h>
#include <list>
#include <algorithm>
#include <map>
#include <iostream>
#include <PointData.h>


void aStar(Graph<PointData, int>::iterator start, Graph<PointData, int>::iterator finish);
void formic(Graph<PointData, int>::iterator start, Graph<PointData, int>::iterator finish);

int main() {

    Graph<PointData, int> graph;
    Graph<PointData, int>::iterator start = graph.getIterator(0);
    Graph<PointData, int>::iterator finish = graph.getIterator(5);
    aStar(start, finish);
    system("pause");

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

        for (int i = 0; i < closedPoints.back().point->lines.size(); i++) {
            Graph<PointData, int>::iterator child = closedPoints.back();
            child.next(i);

            auto uIterator = std::find(closedPoints.begin(), closedPoints.end(), child);
            auto qIterator = std::find(openedPoints.begin(), openedPoints.end(), child);

            child.point->data.wayWeight = parent.point->data.wayWeight + parent.point->lines[i].data;

            if (uIterator == closedPoints.end()) {
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