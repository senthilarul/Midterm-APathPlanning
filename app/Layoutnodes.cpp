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
 * @file      Layoutnodes.cpp
 * @author    Senthil Hariharan Arul
 * @copyright MIT License
 * @brief     Implementation of Layoutnodes class method
 */

#include "Layoutnodes.hpp"

void Layoutnodes::setNodeIndex(int index, int column, int row) { 
    nodeIndex = index;
    columnIndex = column;
    rowIndex = row;
    }

void Layoutnodes::setParentIndex(int pIndex) { 
    parentIndex = pIndex;
}

int Layoutnodes::getParentIndex() {
    return parentIndex;
}

void Layoutnodes::setHeuristicCost(double heuristic) { 
    heuristicCost = heuristic;
}

void Layoutnodes::setPathCost(double cost) { 
    pathCost = cost;
}

void Layoutnodes::setTotalCost() { 
    totalCost = pathCost + 0.1*heuristicCost;
}

void Layoutnodes::setCost(double cost) {
    totalCost = cost;
}

void Layoutnodes::output() { 
    std::cout<<rowIndex<<" "<<columnIndex<<std::endl;
}

double Layoutnodes::getCost() { 
    return totalCost;
}

int Layoutnodes::getRowIndex() { 
    return rowIndex;
}

int Layoutnodes::getColumnIndex() {
    return columnIndex;
}

int Layoutnodes::getIndex() {
    return nodeIndex;
}

double Layoutnodes::returnHCost() { 
    return heuristicCost;
}

