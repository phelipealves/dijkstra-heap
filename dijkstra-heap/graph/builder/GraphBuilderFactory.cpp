#include "GraphBuilderFactory.h"

GraphBuilder *GraphBuilderFactory::getInstance(std::string driver) {
    if(driver.compare("dimacs") == 0) {
        return new DimacsGraphBuilder();
    }
    std::cout << "Graph builder " << driver << " not found." << std::endl;
    return NULL;
}

