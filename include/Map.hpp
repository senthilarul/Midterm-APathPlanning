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
 * @file      Map.hpp
 * @author    Senthil Hariharan Arul
 * @copyright MIT License
 * @brief     Map Class declaration
 * @detail    declares functions for loading and storing maps
 */
#pragma once
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
/**
 * @brief Class Map
 * The following class Map aids in storing and retriving the layout
 * map of the warehouse.
 */
class Map {
 private:
    std::vector<int> currentMap;
    int totalMap;
    int column = 7;
    int row = 4;
    int moveDirection[8] = {-1, 0,    // top
                             0, 1,    // right
                             1, 0,    // bottom
                             0, -1};  // left

 public:
    /**
     * @brief Function displayMap
     * @param none
     * @return none
     * The following function displays the map
     * from input .csv file.
     */
    void displayMap();
    /**
     * @brief Function storeMap
     * @param map of type std::vector<int>
     * @return none
     * The following function store the input vector as
     * as the current map.
     */
    void storeMap(std::vector<int> map);
    /**
     * @brief Function loadMap
     * @param mapPath of type string
     * @return none
     * The following and creates a vector of the map
     * from input .csv file.
     */
    void loadMap(std::string mapPath);
    /**
     * @brief Function getMap
     * @param none
     * @return currentMap of type vector<int>
     * The following function returns current map
     * as a vector<int>.
     */
    std::vector<int> getMap();
    /**
     * @brief Function deleteMap
     * @param none
     * @return none
     * The following function to delete the map.
     */
    void deleteMap();
    /**
     * @brief Function returnColumn
     * @param none
     * @return column of type int
     * The following function returns the columns in the map.
     */
    int returnColumn();
    /**
     * @brief Function returnRow
     * @param none
     * @return row of type int
     * The following function returns the rows in the map.
     */
    int returnRow();
    /**
     * @brief Function setColumn
     * @param colCount of type int
     * @return none
     * sets a value for the columns of nodes in the map.
     */
    void setColumn(int colCount);
    /**
     * @brief Function setRow
     * @param rowCount of type int
     * @return none
     * sets a value for the rows of nodes in the map.
     */
    void setRow(int rowCount);
    /**
     * @brief Function returnDirection
     * @param none
     * @return moveDirections of type int array
     * The return the possible movement directions of the robot.
     * (4 in this case north, east, south and west).
     */
    int* returnDirection();
};
