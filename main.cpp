#include <d-ary-heap/DAryHeap.h>
#include <graph/Graph.h>
#include <dijkstra/Dijkstra.h>
#include <graph/builder/DimacsGraphBuilder.h>

using namespace std;

int main()
{
    Graph *graph = DimacsGraphBuilder::build("/home/bruno/Downloads/USA-road-d.NY.gr");
    Dijkstra *dijkstra = new Dijkstra(graph, new DAryHeap(3), 1);
    dijkstra->run();

    dijkstra->print();
    cout << "FINISHED" << endl;
    cout.flush();

    return 0;
}