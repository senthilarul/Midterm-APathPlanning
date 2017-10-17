#include <iostream>

class Layoutnodes {
 private:
    int nodeIndex;
    int parentIndex;
    int rowIndex;
    int columnIndex;
    double heuristicCost;
    double pathCost;
    double totalCost;

 public:
    void setNodeIndex(int index, int column, int row); //
    void setParentIndex(int pIndex); //
    int getParentIndex(); //
    void setHeuristicCost(double heuristic); //
    void setPathCost(double cost); //
    void setTotalCost(); ///
    void setCost(double cost);
    void output();
    double getCost(); //
    int getRowIndex(); 
    int getColumnIndex();
    int getIndex();
    double returnHCost();
};
