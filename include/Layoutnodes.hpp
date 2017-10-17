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
 * @file      Layoutnodes.hpp
 * @author    Senthil Hariharan Arul
 * @copyright MIT License
 * @brief     Layoutnodes Class declaration
 * @detail    Class to store the path cost, heuristic cost, parent
 *            id for the nodes 
 */

#include <iostream>

/**
 * @brief Class Layoutnodes
 * The following class Layoutnodes stores details regarding the nodes
 * of a map. It store data regarding index of the node, its parent,
 * costs, row and column index.
*/
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
    /**
     * @brief Function setNodeIndex
     * @param index of type int
     * @param column of type int
     * @param row of type int
     * @return none
     * The following function stores the index for a node
     */
    void setNodeIndex(int index, int column, int row);
    /**
     * @brief Function setParentIndex
     * @param pIndex of type int
     * @return none
     * The following function initializes the parent (pIndex)
     * of the node.
     */
    void setParentIndex(int pIndex);
    /**
     * @brief Function getParentIndex
     * @param none
     * @return parentIndex of type int
     * Returns the the parent index of the node.
     */
    int getParentIndex();
    /**
     * @brief Function setHeuristicCost
     * @param heuristic of type double
     * @return none
     * Stores the heuristic cost of the node.
     */
    void setHeuristicCost(double heuristic);
    /**
     * @brief Function setPathCost
     * @param cost of type double
     * @return none
     * The following function sets the pathCost
     * of the node.
     */
    void setPathCost(double cost);
    /**
     * @brief Function setTotalCost
     * @param none
     * @return none
     * The following function calculates the totalCost 
     * from heuristic and path cost.
     */
    void setTotalCost();
    /**
     * @brief Function setCost
     * @param cost of type double
     * @return none
     * The following function sets the totalcost
     * of the node.
     */
    void setCost(double cost);
    /**
     * @brief Function output
     * @param none
     * @return none
     * Prints row and colum index (used in testing).
     */
    void output();
    /**
     * @brief Function getCost
     * @param none
     * @return totalCost of type double
     * The following function returns the totalCost of the node
     */
    double getCost();
    /**
     * @brief Function getRowIndex
     * @param none
     * @return rowIndex of type int
     * The following function returns rowIndex of the node.
     */
    int getRowIndex(); 
    /**
     * @brief Function getColumnIndex
     * @param none
     * @return columnIndex of type int
     * Returns column index of the node.
     */
    int getColumnIndex();
    /**
     * @brief Function getIndex
     * @param none
     * @return nodeIndex of type int
     * The following function returns the node index
     */
    int getIndex();
    /**
     * @brief Function returnHCost
     * @param none
     * @return heursiticCost of type double
     * The following function returns the hueristic cost
     * of the node.
     */
    double returnHCost();
};
