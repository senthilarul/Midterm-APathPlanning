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
 * @file      Astar.cpp
 * @author    Senthil Hariharan Arul
 * @copyright MIT License
 * @brief     Implementation of Astar class methods
 * @detail    Contains functions for path planning calculations and visualizing 
 *            the path.
 */

#include <math.h>
#include <typeinfo>
#include <vector>
#include <list>
#include "Astar.hpp"

#define OBSTACLE 9999

// #define testing
bool Astar::createNodeList(Map warehouseLayout, int startPt, int endPt) {
    std::vector<int> map = warehouseLayout.getMap();
    Layoutnodes node;
    mapColumn = warehouseLayout.returnColumn();
    mapRow = warehouseLayout.returnRow();
    int index = 0;
    for (int i = 0; i < mapRow; i++) {
        for (int j = 0; j < mapColumn; j++) {
            if (map[i*mapColumn + j] == 1) {
                node.setNodeIndex(index++, j, i);
                nodeList.emplace_back(node);
            }
        }
    }
    #ifdef testing
    for (int i =0; i < index; i++) {
        nodeList[i].output();
    }
    #endif
    if (startPt >= 0 && endPt >= 0 && (unsigned)startPt < nodeList.size() && (unsigned)endPt < nodeList.size()) {
        setStartPoint(startPt);
        setEndPoint(endPt);
        return true;
    } else {
        return false;
    }
}

void Astar::setStartPoint(int startIndex) {
    startPoint = startIndex;
    // startPoint = 2;
}

void Astar::setEndPoint(int endIndex) {
    endPoint = endIndex;
    // endPoint = 12;
}

int Astar::planPath() {
    nodeList[startPoint].setHeuristicCost(1);
    nodeList[startPoint].setPathCost(0);
    nodeList[startPoint].setTotalCost();

    for (auto a : nodeList) {
        calcHeuristicCost(a.getIndex(), nodeList[endPoint]);
    }

    openList.emplace_back(nodeList[startPoint]);
    #ifdef testing
    for (auto i : openList) {
        std::cout << "cost" << i.getCost() << std::endl;
    }
    // std::cout << "openList: " << openList.size() << std::endl;
    #endif

    Map map;
    auto directions = map.returnDirection();
    int finalFoundFlag = 0;
    while (!openList.empty()) {
        openList.sort(priority);
        Layoutnodes currentNode = openList.front();
        closedList.emplace_back(currentNode);
        // std::cout << "after transfer: " << currentNode.getCost() << std::endl;
        openList.pop_front();

        if (currentNode.getIndex() == nodeList[endPoint].getIndex()) {
            // std::cout << "final found";
            finalFoundFlag = 1;
            #ifdef testing
            for (auto i : closedList) {
                std::cout << "\n Node Index: "<< i.getIndex() << " hcost: " << i.returnHCost() << "  totalcost: " << i.getCost() << " Parent: " << i.getParentIndex();
            }
            #endif
            break;
        } else {
        // neighbour
        int cRow = currentNode.getRowIndex();
        int cCol = currentNode.getColumnIndex();
        // std::cout << "\ncrow " << cRow << "\tccol " << cCol;
        std::vector<int> neighbourID;
        for (int i = 0; i < 4; i++) {
            int x = directions[2*i] + cRow;
            int y = directions[2*i +1] + cCol;
            // std::cout << "\nx: " << x << "y: " << y << std::endl;
            if (x < 0 || y < 0 || x > 3 || y > 6) {
            continue;
            } else {
                int id = identifyNode(x, y);
                if (id != OBSTACLE) {
                    bool closed = inClosedList(id);
                    if (closed == true) {
                        continue;
                    } else {
                        bool open1 = inOpenList(id);
                        if (open1 == false) {
                            neighbourID.emplace_back(id);
                        }
                    }
                }
            }
        }
        for (auto i : neighbourID) {
            nodeList[i].setParentIndex(currentNode.getIndex());
            nodeList[i].setPathCost(1);
            nodeList[i].setTotalCost();
            openList.push_back(nodeList[i]);
            #ifdef testing
            std::cout << "\nThe openlist size is: " << openList.size();
            std::cout << "\nThe closedlist size is: " << closedList.size();
            #endif
        }
        }
    }
    std::list<Layoutnodes> pathBuffer = closedList;
    pathBuffer.reverse();
    Layoutnodes frontNode = pathBuffer.front();
    path.emplace_back(frontNode);
    pathBuffer.pop_front();
    for (auto i : pathBuffer) {
        Layoutnodes temp = path.back();
        if (temp.getParentIndex() == i.getIndex()) {
            path.emplace_back(i);
        } else {
            continue;
        }
    }
    #ifdef testing
    for (auto i : path) {
        std::cout << "\nPath list: " << i.getIndex();
    }
    #endif
    int shortestPathLength = 0;
    if (finalFoundFlag == 0) {
        shortestPathLength = -1;
    } else {
        shortestPathLength = (closedList.size()-1);
    }
    return shortestPathLength;
}

bool Astar::inOpenList(int id) {
    int openFlag = 0;
    for (auto l : openList) {
        if (l.getIndex() == id) {
            if (l.getCost() > nodeList[id].getCost()) {
                l.setCost(nodeList[id].getCost());
            }
            openFlag = 1;
        }
    }
    if (openFlag == 1) {
        return true;
    } else {
        return false;
    }
}

int Astar::identifyNode(int x, int y) {
    int found = 0;
    int index = 0;
    for (auto n : nodeList) {
        // std::cout<<"\n row col"<<n.getRowIndex()<<" "<<n.getColumnIndex();
        if (n.getRowIndex() == x && n.getColumnIndex() == y) {
            found = 1;
            index = n.getIndex();
        }
    }
    if (found == 1) {
        return index;
    } else {
        return OBSTACLE;
    }
}

bool Astar::inClosedList(int id) {
    int closedFlag = 0;
    for (auto l : closedList) {
        if (l.getIndex() == id)
           closedFlag = 1;
    }
    if (closedFlag == 1)
        return true;
    else
        return false;
}


void Astar::calcHeuristicCost(int node, Layoutnodes goal) {
    int x1 = nodeList[node].getColumnIndex();
    int y1 = nodeList[node].getRowIndex();
    int x2 = goal.getColumnIndex();
    int y2 = goal.getRowIndex();
    double distance = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    nodeList[node].setHeuristicCost(distance);
}

Mat Astar::displayMap() {
    int sqW = 50;
    int iSqW = 45;
    int xLength = mapColumn*sqW, yLength = mapRow*sqW+40;
    drawing = Mat::zeros(Size(xLength, yLength), CV_8UC3);
    for (int i = 0; i < mapRow; i++) {
        for (int j = 0; j < mapColumn; j++) {
            int pathFlag = 0;
            int blockFlag = 1;
            int firstPt = 0, lastPt = 0;
            for (auto n : path) {
                if (n.getRowIndex() == i && n.getColumnIndex() == j) {
                    pathFlag = 1;
                    if (n.getIndex() == startPoint)
                       firstPt = 1;
                    else if (n.getIndex() == endPoint)
                       lastPt = 1;
                }
            }
            for (auto n : nodeList) {
                if (n.getRowIndex() == i && n.getColumnIndex() == j) {
                    blockFlag = 0;
                }
            }
            if (pathFlag == 1) {
                rectangle(drawing, Point(j*sqW, i*sqW), Point(j*sqW+sqW, i*sqW+sqW), Scalar(255, 255, 255), 1, CV_AA, 0);
                if (firstPt == 1)
                rectangle(drawing, Point(j*sqW+2, i*sqW+2), Point(j*sqW+2+iSqW, i*sqW+2+iSqW), Scalar(0, 255, 255), -1, CV_AA, 0);
                else if (lastPt == 1)
                rectangle(drawing, Point(j*sqW+2, i*sqW+2), Point(j*sqW+2+iSqW, i*sqW+2+iSqW), Scalar(0, 0, 255), -1, CV_AA, 0);
                else
                rectangle(drawing, Point(j*sqW+2, i*sqW+2), Point(j*sqW+2+iSqW, i*sqW+2+iSqW), Scalar(0, 255, 0), -1, CV_AA, 0);
            } else if (blockFlag == 1) {
                rectangle(drawing, Point(j*sqW, i*sqW), Point(j*sqW+sqW, i*sqW+sqW), Scalar(255, 255, 255), 1, CV_AA, 0);
                rectangle(drawing, Point(j*sqW+2, i*sqW+2), Point(j*sqW+2+iSqW, i*sqW+2+iSqW), Scalar(128, 128, 128), -1, CV_AA, 0);
            } else {
                rectangle(drawing, Point(j*sqW, i*sqW), Point(j*sqW+sqW, i*sqW+sqW), Scalar(255, 255, 255), 1, CV_AA, 0);
              }
       }
    }
    rectangle(drawing, Point(10, yLength-35), Point(20, yLength-25), Scalar(0, 255, 255), -1, CV_AA, 0);
    putText(drawing, "- Start Point", Point(25, yLength-25), FONT_HERSHEY_SIMPLEX, 0.3, Scalar(255, 255, 255), 1, 16);
    rectangle(drawing, Point(100, yLength-35), Point(110, yLength-25), Scalar(0, 0, 255), -1, CV_AA, 0);
    putText(drawing, "- End Point", Point(125, yLength-25), FONT_HERSHEY_SIMPLEX, 0.3, Scalar(255, 255, 255), 1, 16);
    rectangle(drawing, Point(10, yLength-15), Point(20, yLength-5), Scalar(0, 255, 0), -1, CV_AA, 0);
    putText(drawing, "- Path", Point(25, yLength-10), FONT_HERSHEY_SIMPLEX, 0.3, Scalar(255, 255, 255), 1, 16);
    rectangle(drawing, Point(100, yLength-15), Point(110, yLength-5), Scalar(128, 128, 128), -1, CV_AA, 0);
    putText(drawing, "- Obstacle", Point(125, yLength-10), FONT_HERSHEY_SIMPLEX, 0.3, Scalar(255, 255, 255), 1, 16);
return drawing;
}

bool priority(Layoutnodes &node1, Layoutnodes &node2) {
    if (node1.getCost() < node2.getCost())
        return true;
    else
        return false;
}
