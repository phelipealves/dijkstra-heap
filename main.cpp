#include <d-ary-heap/DAryHeap.h>
#include <dijkstra/Dijkstra.h>
#include <graph/builder/GraphBuilderFactory.h>
#include <cputimer/CPUTimer.h>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
    /* initialize random seed: */
    srand ((unsigned int) time(NULL));

    int numExecutions = (strcmp(argv[1], "-k") == 0) ? atoi(argv[2]) : 1;
    int dAryHeapD = (strcmp(argv[3], "-d") == 0) ? atoi(argv[4]) : 2;
    GraphBuilder *builder = GraphBuilderFactory::getInstance("dimacs");

    CPUTimer builder_time;
    builder_time.start();

    Graph *graph = builder->build();
    builder_time.stop();

    cout << "Finished graph creation..." << endl << "Graph load time: " << builder_time.getCronoTotalSecs() << endl << endl;

    map<int, vector<Vertex*>*> *valueFont = new map<int, vector<Vertex*>*>();
    vector<int> *degrees = new vector<int>();
    for (std::vector<Vertex*>::iterator it = graph->getVertices()->begin() ; it != graph->getVertices()->end() - 1; ++it) {
        int degree = (int) (*it)->getEdges()->size();
        if((*valueFont)[degree] == nullptr) {
            (*valueFont)[degree] = new  vector<Vertex*>();
            degrees->push_back(degree);
        }
        (*valueFont)[degree]->push_back(*it);
    }
    std::sort (degrees->begin(), degrees->end());
    int meanSize = (int) (degrees->size() / 3);
    int rest = (int) (degrees->size() % 3);
    int min = meanSize, mean = (meanSize + rest), max = meanSize;
    int initMin = 0, endMin = min-1;
    int initMean = endMin+1, endMean = (min+mean - 1);
    int initMax = endMean+1, endMax = (int) (degrees->size() - 1);

    // Begin execution:
    int selectedMin = rand() % min + initMin;
    int selectedMean = rand() % mean + initMean;
    int selectedMax = rand() % max + initMax;

    std::string traceDateTime = Utils::currentDateTime();

    std::ofstream logFile;
    logFile.open (std::string("dijkstra_out_").append(traceDateTime).append("_global"));
    logFile << "p\t" << graph->getNumVertices() << "\t" << graph->getNumEdges() << std::endl;
    for (int k = 0; k < degrees->size(); k++) {
        logFile << "d\t" << (*degrees)[k] << "\t" << (*valueFont)[(*degrees)[k]]->size() << std::endl;
    }

    double totalExecutionTime = 0;
    std::string traceName;
    std::string traceType;
    bool isFirstDiscated = false;
    for(int i = 0; i < numExecutions; i++) {
        int selectedMinVertex = (*(*valueFont)[(*degrees)[selectedMin]])[(rand() % (*valueFont)[(*degrees)[selectedMin]]->size())]->getId();
        int selectedMeanVertex = (*(*valueFont)[(*degrees)[selectedMean]])[(rand() % (*valueFont)[(*degrees)[selectedMean]]->size())]->getId();
        int selectedMaxVertex = (*(*valueFont)[(*degrees)[selectedMax]])[(rand() % (*valueFont)[(*degrees)[selectedMax]]->size())]->getId();

        int selectedVertex;
        for(int j = 0; j < 3; j++) {
            AbstractHeap *heap = new DAryHeap(dAryHeapD, graph);

            switch(j) {
                case 0:
                    selectedVertex = selectedMinVertex;
                    traceType = std::string("min");
                    break;
                case 1:
                    selectedVertex = selectedMeanVertex;
                    traceType = std::string("mean");
                    break;
                default:
                case 2:
                    selectedVertex = selectedMaxVertex;
                    traceType = std::string("max");
                    break;
            }
            traceName = std::string().append(traceType).append("_").append(std::to_string(i + 1)).append("_")
                    .append(traceDateTime);

            CPUTimer dijkstra_time;
            dijkstra_time.start();

            Dijkstra *dijkstra = new Dijkstra(graph, heap, selectedVertex, traceName);
            dijkstra->run();

            dijkstra_time.stop();

            // Reset Vertex distances
            for(int vertexNum = 0; vertexNum < graph->getNumVertices(); vertexNum++) {
                graph->getVertex(vertexNum+graph->getInitialVertex())->setDistance(INT_MAX);
            }

            if(i == 0 && j == 0 && !isFirstDiscated) {
                j--;
                isFirstDiscated = true;
                free(heap);
                free(dijkstra);
                continue;
            }

            totalExecutionTime += dijkstra_time.getCPUTotalSecs();
            logFile << "t\t" << (i+1) << "\t" << traceType << "\t" << selectedVertex << "\t" <<
                    dijkstra_time.getCPUTotalSecs() << std::endl;

            free(heap);
            free(dijkstra);
        }
    }

    logFile << "t\t" << "total" << "\t" << totalExecutionTime << std::endl;
    logFile.close();

    cout << "FINISHED" << endl;

    return 0;
}