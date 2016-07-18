#include <d-ary-heap/DAryHeap.h>
#include <graph/Graph.h>
#include <dijkstra/Dijkstra.h>
#include <graph/builder/DimacsGraphBuilder.h>
#include <graph/builder/GraphBuilderFactory.h>

#define DARYHEAP_D  4
#define DIJKSTRA_START_NODE 1

using namespace std;

int main(int argc, char **argv)
{
    string driver = (strcmp(argv[1], "-d") == 0) ? argv[2] : "dimacs";
    GraphBuilder *builder = GraphBuilderFactory::getInstance(driver);

    clock_t start_time = clock();
    Graph *graph = builder->build();
    clock_t graph_load_time = clock();
    cout << "Finished graph creation..." << endl <<
            "Graph load time: " << graph_load_time - start_time << endl << endl;

    Dijkstra *dijkstra = new Dijkstra(graph, new DAryHeap(DARYHEAP_D), DIJKSTRA_START_NODE);
    clock_t dijkstra_start_time = clock();
    dijkstra->run();
    clock_t dijkstra_end_time = clock();

    cout << "Start time: " << start_time << endl <<
            "Graph load time: " << graph_load_time - start_time << endl <<
            "Dijkstra run time: " << dijkstra_end_time - dijkstra_start_time << endl <<
            "Finish time: " << dijkstra_end_time << endl;

    //dijkstra->print();
    cout << "FINISHED" << endl;
    cout.flush();

    return 0;
}