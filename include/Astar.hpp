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
 * @file      Astar.hpp
 * @author    Senthil Hariharan Arul
 * @copyright MIT License
 * @brief     Astar Class declaration
 * @detail    Declares functions for identifying nodes in a map,
 *            planning path, calculating total cost and displaying 
 *            selected path
 */

#pragma once

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include "Layoutnodes.hpp"
#include "Map.hpp"


using cv::Mat;
using cv::imshow;
using cv::waitKey;
using cv::Scalar;
using cv::Point;
using cv::Size;
using cv::FONT_HERSHEY_SIMPLEX;

/**
 * @brief Class Astar
 * The following class Astar aids in calculation of the the shortest path
 * between the user input start and end point using Astar path planning. 
 * It also implements a method displayMap to produce a image of the path
 * using OpenCV.
*/
class Astar {
 private:
    int startPoint;
    int endPoint;
    int mapColumn;
    int mapRow;
    std::list<Layoutnodes> openList;
    std::list<Layoutnodes> closedList;
    std::vector<Layoutnodes> nodeList;
    std::vector<double> neighbourNodes;
    std::list<Layoutnodes> path;
    cv::Mat drawing;

 public:
    /**
     * @brief constructor Astar
     * @param none
     * @return none
     * initializes values of startPoint, endPoint, mapColumn
     * and mapRow. 
     */
    Astar() {
    startPoint = 0;
    endPoint = 0;
    mapColumn = 0;
    mapRow = 0;
    }
    /**
     * @brief Function SetStartPoint
     * @param startIndex of type int
     * @return none
     * The following function initializes the values of user defined
     * start point in the map.
     */
    void setStartPoint(int startIndex);
    /**
     * @brief Function SetEndPoint
     * @param endIndex of type int
     * @return none
     * The following function initializes the values of user defined
     * end(goal) point in the map.
     */
    void setEndPoint(int endIndex);
    /**
     * @brief Function calcPathCost
     * @param id of type int
     * @return none
     * calculates path cost between current node and parent node.
     */
    void calcPathCost(int id);
    /**
     * @brief Function calcHeuristicCost
     * @param node of type int
     * @param goal of type Layoutnodes
     * @return none
     * The following function calculates the straight line
     * cost between current node and end(goal) point.
     */
    void calcHeuristicCost(int node, Layoutnodes goal);
    /**
     * @brief Function createNodeList
     * @param warehouseLayout of type Map
     * @param startPt of type int
     * @param endPt of type int
     * @return bool (true or false)
     * The following function creates a list of possible nodes
     * (neglecting obstacles) for the given Map.
     */
    bool createNodeList(Map warehouseLayout, int startPt, int endPt);
    /**
     * @brief Function plaanPath
     * @param none
     * @return shortestPathLength of type int
     * The following function implements the A* algorithm and
     * identifies the shortest path.
     */
    int planPath();
    /**
     * @brief Function identifyNode
     * @param x of type int
     * @param y of type int
     * @return index of type int
     * The following function identifies the node index from the
     * row and column values of the node.
     */
    int identifyNode(int x, int y);
    /**
     * @brief Function inOpenList
     * @param id of type int
     * @return bool value
     * The following function returns true if a node of the given
     * is in the openList, else returns false.
     */
    bool inOpenList(int id);
    /**
     * @brief Function inClosedList
     * @param id of type int
     * @return bool value
     * The following function returns true if a node of the given
     * is in the closeList, else returns false.
     */
    bool inClosedList(int id);
    /**
     * @brief Function displayMap
     * @param none
     * @return display of type Mat (OpenCV Matrix)
     * The following function returns true if a node of the given
     * is in the closeList, else returns false.
     */
    cv::Mat displayMap();
    /**
     * @brief destructor Astar
     * @param none
     * @return none 
     */
    ~Astar() {}
};
   /**
     * @brief Function priority
     * @param reference to node1 of type Layoutnodes
     * @param reference to node2 of type Layoutnodes
     * @return bool value
     * The following function returns true if a node1 cost is less
     * than node2 cost, else false.
     */
    bool priority(Layoutnodes &node1, Layoutnodes &node2);

