//map
#include <iostream>
#include <fstream>
#include <sstream> //change
#include <vector>
#include <string.h>

class Map {
 private:
    std::vector<int> currentMap;
    int totalMap;
    int column = 7;
    int row = 4;
    int moveDirection[8] = {-1,0,    // top
                             0,1,    // right
                             1,0,    // bottom
                             0,-1};  // left 

 public:
    void displayMap();
    void storeMap(std::vector<int> map);
    void loadMap(std::string mapPath);
    std::vector<int> getMap();
    void deleteMap();
    int returnColumn();  //auto
    int returnRow();  //auto
    void setColumn(int colCount);
    void setRow(int rowCount);
    std::vector<int> returnMap();
    int* returnDirection();
};
