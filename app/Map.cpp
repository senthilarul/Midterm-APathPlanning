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
    rowCount = row;
}

std::vector<int> Map::returnMap() {
    return currentMap;
}

int* Map::returnDirection() {
    return moveDirection;
}
