#include <gtest/gtest.h>
#include <memory>
#include "Map.hpp"

std::shared_ptr<Map> testMap = std::make_shared<Map>();
std::vector<int> testMapArray1 {1,1,1,1,0,0,0,0,
			        0,0,0,1,1,0,0,0,
			        0,0,1,1,1,1,1,0,
			        1,1,1,1,1,1,1,0};

TEST(MapLoadMapTest, testLoadMapMethodWithDefaultMap)
{
    testMap->loadMap("../Data/data1.csv");
    ASSERT_EQ(testMap->returnColumn(), 8);
    ASSERT_EQ(testMap->returnRow(), 4);
    ASSERT_EQ(testMap->getMap(), testMapArray1);
}

