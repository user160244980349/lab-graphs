#include <Graph.h>
#include <list>
#include <PointData.h>
#include <LineData.h>
#include <formic.h>
#include <cstdlib>


int main() {

    std::vector<typename Graph<PointData, LineData>::point> points({
        Graph<PointData, LineData>::point({5,0,0}),
        Graph<PointData, LineData>::point({19,0,0}),
        Graph<PointData, LineData>::point({9,0,0}),
        Graph<PointData, LineData>::point({6,0,0}),
        Graph<PointData, LineData>::point({7,0,0}),
        Graph<PointData, LineData>::point({8,0,0})
    });

    points[0].lines.emplace_back(Graph<PointData, LineData>::line({10, 1}, &points[1]));
    points[0].lines.emplace_back(Graph<PointData, LineData>::line({20, 1}, &points[2]));
    points[1].lines.emplace_back(Graph<PointData, LineData>::line({5, 1}, &points[5]));
    points[2].lines.emplace_back(Graph<PointData, LineData>::line({5, 1}, &points[3]));
    points[2].lines.emplace_back(Graph<PointData, LineData>::line({5, 1}, &points[4]));
    points[3].lines.emplace_back(Graph<PointData, LineData>::line({5, 1}, &points[5]));
    points[4].lines.emplace_back(Graph<PointData, LineData>::line({5, 1}, &points[5]));

    Graph<PointData, LineData> graph(points);

    Graph<PointData, LineData>::iterator start = graph.getIterator(0);
    Graph<PointData, LineData>::iterator finish = graph.getIterator(5);

//    aStar(start, finish);
    formic(start, finish);

    system("pause");

    return 0;
}