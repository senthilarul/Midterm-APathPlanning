#include <iostream>
#include <list>
#include <memory>
#include "Layoutnodes.hpp"
#include "Map.hpp"


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

 public:
    void setStartPoint(int startIndex);
    void setEndPoint(int endIndex);
    void calcPathCost(int id);
    void calcHeuristicCost(int node, Layoutnodes goal);
    bool createNodeList(Map warehouseLayout, int startPt, int endPt);
    int planPath();
    int identifyNode(int x, int y);
    bool inOpenList(int id);
    bool inClosedList(int id); 
    void displayMap();
};

    bool priority( Layoutnodes &node1, Layoutnodes &node2);

