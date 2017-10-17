#include <iostream>
#include <memory>
#include <list>
#include <vector>
#include "Astar.hpp"

#define debug

int main() {
    Astar a;
    Map warehouseMap;
    #ifdef debug
    std::vector<int> mapArray {1,1,1,1,0,1,0,
			       0,0,0,1,1,0,0,
			       0,0,1,1,1,1,1,
			       1,1,1,1,1,1,0};
    #endif
    int startPt,endPt;
    int userChoice;
    int noOfSteps;
    // menu
    std::cout<<"Astar Path Planning using C++"<<std::endl;
    std::cout<<"Choose which map to use: "<<std::endl;
    std::cout<<"1) default map"<<std::endl;
    std::cout<<"2) load map"<<std::endl;
    std::cin>>userChoice;
    if(userChoice == 1) {
        warehouseMap.storeMap(mapArray);
        warehouseMap.displayMap();
    }
    else {
        std::cout<<"Please Enter the full path of the Map (.csv) file";
        std::cout<<std::endl;
        std::string mapPath;
        std::cin>>mapPath;
        warehouseMap.loadMap(mapPath);
        warehouseMap.displayMap();
    }
    std::cout<<"Enter Start and End points: "<<std::endl;
    std::cin>>startPt>>endPt;
    bool success = a.createNodeList(warehouseMap, startPt-1,endPt-1);
    if(success == true) {
        noOfSteps = a.planPath();
        a.displayMap();
    }
    else {
        std::cout<<"Enter a valid start and end point"<<std::endl;
    }
    std::cout<<"Number of Steps taken in the shortest path is: ";
    std::cout<<noOfSteps<<std::endl;
    return 0;
}
