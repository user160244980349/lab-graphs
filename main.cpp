#include <Graph.h>
#include <list>
#include <PointData.h>
#include <LineData.h>
#include <formic.h>
#include <aStar.h>
#include <cstdlib>


int main() {

    std::vector<typename Graph<PointData, LineData>::point> points({
        Graph<PointData, LineData>::point({20,0,0}),
        Graph<PointData, LineData>::point({17,0,0}),
        Graph<PointData, LineData>::point({15,0,0}),
        Graph<PointData, LineData>::point({16,0,0}),
        Graph<PointData, LineData>::point({15,0,0}),
        Graph<PointData, LineData>::point({13,0,0}),
        Graph<PointData, LineData>::point({9,0,0}),
        Graph<PointData, LineData>::point({10,0,0}),
        Graph<PointData, LineData>::point({7,0,0}),
        Graph<PointData, LineData>::point({6,0,0}),
        Graph<PointData, LineData>::point({7,0,0}),
        Graph<PointData, LineData>::point({9,0,0}),
        Graph<PointData, LineData>::point({5,0,0}),
        Graph<PointData, LineData>::point({2,0,0}),
        Graph<PointData, LineData>::point({2,0,0}),
        Graph<PointData, LineData>::point({3,0,0}),
        Graph<PointData, LineData>::point({1,0,0}),
    });

    points[0].lines.emplace_back(Graph<PointData, LineData>::line({13, 1}, &points[1]));
    points[0].lines.emplace_back(Graph<PointData, LineData>::line({12, 1}, &points[2]));
    points[0].lines.emplace_back(Graph<PointData, LineData>::line({11, 1}, &points[3]));
    points[1].lines.emplace_back(Graph<PointData, LineData>::line({9, 1}, &points[4]));
    points[1].lines.emplace_back(Graph<PointData, LineData>::line({7, 1}, &points[5]));
    points[2].lines.emplace_back(Graph<PointData, LineData>::line({4, 1}, &points[5]));
    points[2].lines.emplace_back(Graph<PointData, LineData>::line({8, 1}, &points[6]));
    points[3].lines.emplace_back(Graph<PointData, LineData>::line({10, 1}, &points[6]));
    points[3].lines.emplace_back(Graph<PointData, LineData>::line({5, 1}, &points[7]));
    points[3].lines.emplace_back(Graph<PointData, LineData>::line({7, 1}, &points[10]));
    points[4].lines.emplace_back(Graph<PointData, LineData>::line({2, 1}, &points[8]));
    points[4].lines.emplace_back(Graph<PointData, LineData>::line({1, 1}, &points[11]));
    points[5].lines.emplace_back(Graph<PointData, LineData>::line({5, 1}, &points[8]));
    points[5].lines.emplace_back(Graph<PointData, LineData>::line({5, 1}, &points[9]));
    points[5].lines.emplace_back(Graph<PointData, LineData>::line({10, 1}, &points[12]));
    points[6].lines.emplace_back(Graph<PointData, LineData>::line({4, 1}, &points[9]));
    points[6].lines.emplace_back(Graph<PointData, LineData>::line({3, 1}, &points[10]));
    points[6].lines.emplace_back(Graph<PointData, LineData>::line({5, 1}, &points[13]));
    points[7].lines.emplace_back(Graph<PointData, LineData>::line({2, 1}, &points[10]));
    points[7].lines.emplace_back(Graph<PointData, LineData>::line({6, 1}, &points[14]));
    points[8].lines.emplace_back(Graph<PointData, LineData>::line({3, 1}, &points[11]));
    points[8].lines.emplace_back(Graph<PointData, LineData>::line({3, 1}, &points[12]));
    points[9].lines.emplace_back(Graph<PointData, LineData>::line({3, 1}, &points[13]));
    points[10].lines.emplace_back(Graph<PointData, LineData>::line({4, 1}, &points[13]));
    points[10].lines.emplace_back(Graph<PointData, LineData>::line({3, 1}, &points[14]));
    points[11].lines.emplace_back(Graph<PointData, LineData>::line({2, 1}, &points[12]));
    points[11].lines.emplace_back(Graph<PointData, LineData>::line({3, 1}, &points[15]));
    points[12].lines.emplace_back(Graph<PointData, LineData>::line({8, 1}, &points[13]));
    points[12].lines.emplace_back(Graph<PointData, LineData>::line({5, 1}, &points[15]));
    points[12].lines.emplace_back(Graph<PointData, LineData>::line({7, 1}, &points[16]));
    points[13].lines.emplace_back(Graph<PointData, LineData>::line({5, 1}, &points[16]));
    points[14].lines.emplace_back(Graph<PointData, LineData>::line({5, 1}, &points[16]));
    points[15].lines.emplace_back(Graph<PointData, LineData>::line({6, 1}, &points[16]));

    Graph<PointData, LineData> graph(points);

    Graph<PointData, LineData>::iterator start = graph.getIterator(0);
    Graph<PointData, LineData>::iterator finish = graph.getIterator(5);

    aStar(start, finish);
    formic(start, finish);

    system("pause");

    return 0;
}
