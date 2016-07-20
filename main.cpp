#include <d-ary-heap/DAryHeap.h>
#include <dijkstra/Dijkstra.h>
#include <graph/builder/GraphBuilderFactory.h>

#define DARYHEAP_D  2
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

    // TEST GRAPH
//    graph = new Graph(true, 0, 8);
//    graph->addEdge(0, 1, 4);
//    graph->addEdge(0, 7, 8);
//    graph->addEdge(1, 2, 8);
//    graph->addEdge(1, 7, 11);
//    graph->addEdge(2, 3, 7);
//    graph->addEdge(2, 8, 2);
//    graph->addEdge(2, 5, 4);
//    graph->addEdge(3, 4, 9);
//    graph->addEdge(3, 5, 14);
//    graph->addEdge(4, 5, 10);
//    graph->addEdge(5, 6, 2);
//    graph->addEdge(6, 7, 1);
//    graph->addEdge(6, 8, 6);
//    graph->addEdge(7, 8, 7);

    clock_t dijkstra_start_time = clock();
    Dijkstra *dijkstra = new Dijkstra(graph, new DAryHeap(DARYHEAP_D, graph), DIJKSTRA_START_NODE);
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