#include <Graph.h>


int main() {

    Graph<int, int> graph;
    Graph<int, int>::iterator it = graph.getIterator(0);

    std::cout << std::endl << "point weight: " << it.pointWeight << "  line weight: " << it.lineWeight << std::endl;
    it.move(0);
    std::cout << "point weight: " << it.pointWeight << "  line weight: " << it.lineWeight << std::endl;
    it.move(1);
    std::cout << "point weight: " << it.pointWeight << "  line weight: " << it.lineWeight << std::endl;

    return 0;
}