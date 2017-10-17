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

