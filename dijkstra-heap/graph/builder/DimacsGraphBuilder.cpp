#include "DimacsGraphBuilder.h"

Graph* DimacsGraphBuilder::build(std::string filePath) {
    Graph *graph = new Graph(false);

    std::string line;
    std::ifstream dimacsFile(filePath);
    if (dimacsFile.is_open()) {
        int lineEntryNum;
        std::string lineType, sourceVertex, destinationVertex, weight;
        char *auxSubstring, *auxLine;
        while (getline(dimacsFile, line))
        {
            lineEntryNum = 0;
            auxLine = strdup(line.c_str());
            auxSubstring = strtok(auxLine, " ");
            while (auxSubstring != NULL)
            {
                switch(lineEntryNum) {
                    case 0:
                        lineType = std::string(auxSubstring);
                        break;
                    case 1:
                        sourceVertex = std::string(auxSubstring);
                        break;
                    case 2:
                        destinationVertex = std::string(auxSubstring);
                        break;
                    case 3:
                        weight = std::string(auxSubstring);
                        break;
                    default:
                        break;
                }
                if(lineType.compare("a")) {
                    break;
                }

                lineEntryNum++;
                auxSubstring = strtok (NULL, " ");
            }

            free(auxLine);
            if(lineType.compare("a")) {
                continue;
            }

            // Once the line is a edge of the graph...
            int srcVertexId = std::stoi(sourceVertex);
            int dstVertexId = std::stoi(destinationVertex);
            int edgeWeight = std::stoi(weight);
            graph->addEdge(srcVertexId, dstVertexId, edgeWeight);
        }

        dimacsFile.close();
    } else {
        std::cout << "Unable to open file";
    }

    return graph;
}

