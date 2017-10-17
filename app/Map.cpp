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
 * @file      Map.cpp
 * @author    Senthil Hariharan Arul
 * @copyright MIT License
 * @brief     Implements methods of Map class
 * @detail    Converts input .csv file to vector of int, returns
 *            number of column and rows 
 */

#include "Map.hpp"


void Map::displayMap() {
    std::vector<int> displayLayout = currentMap;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            if(displayLayout[i*column + j] == 1) {
                std::cout << "o";
            }
            else {
                std::cout << "x";
            }
        }
        std::cout << std::endl;
    }
}

void Map::storeMap(std::vector<int> map) {
    currentMap = map;
}

void Map::loadMap(std::string mapPath) {
    std::ifstream file(mapPath);
    std::string row, cell;
    int rowCount = 0;
    if(file.good()) {
        while(std::getline(file,row)) {
            int columnCount = 0;
            std::istringstream linestream(row);
            while (getline(linestream, cell, ',')) {
                ++columnCount;
                if(cell == "0")
                    currentMap.emplace_back(0);
                else
                    currentMap.emplace_back(1);
            }
            ++rowCount;
            setColumn(columnCount);
        }
    }
    else {
        std::cout<<"The File path entered is not correct";
        setColumn(0);
        setRow(0);
    }
    setRow(rowCount);
}

std::vector<int> Map::getMap() {
    return currentMap;
}

int Map::returnColumn() {
    return column;
}

int Map::returnRow() {
    return row;
}

void Map::setColumn(int colCount) {
    column = colCount;
}

void Map::setRow(int rowCount) {
    row = rowCount;
}

//std::vector<int> Map::returnMap() {
  //  return currentMap;
//}

int* Map::returnDirection() {
    return moveDirection;
}
