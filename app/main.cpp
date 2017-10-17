/******************************************************************************
*  MIT License
*
*  Copyright (c) 2017 Senthil Hariharan Arul
*
*  Permission is hereby granted, free of charge, to any person obtaining a copy
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is
*  furnished to do so, subject to the following conditions:
*
*  The above copyright notice and this permission notice shall be included in all
*  copies or substantial portions of the Software.
*
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*  SOFTWARE.
*******************************************************************************/

/**
 * @file      main.cpp
 * @author    Senthil Hariharan Arul
 * @copyright MIT License
 * @brief     Implements a Demo for Astar path planning
 */
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
        if(noOfSteps == 0) {
            std::cout<<"Start and End Point are same"<<std::endl;
            Mat pathDrawing = a.displayMap();
            imshow("Planned Path", pathDrawing);
            waitKey(0);
        }
        else if(noOfSteps == -1) {
            std::cout<<"The no possible path between the two points";
        }
        else {
            std::cout<<"Number of Steps taken in the shortest path is: ";
            std::cout<<noOfSteps<<std::endl;
            Mat pathDrawing = a.displayMap();
            imshow("Planned Path", pathDrawing);
            waitKey(0);
        }
    }
    else {
        std::cout<<"Enter a valid start and end point"<<std::endl;
    }
    
    return 0;
}
