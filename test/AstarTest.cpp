#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Astar.hpp"
#include <memory>

std::shared_ptr<Astar> testAstar = std::make_shared<Astar>();
std::vector<int> testMapArray {1,1,1,1,0,1,0,
			       0,0,0,1,1,0,0,
			       0,0,1,1,1,1,1,
			       1,1,1,1,1,1,0};


TEST(AstarCreateNodeTest1, testCreateNodeForOutOfBoundStartandEndPt) {
    Map testMap;
    testMap.storeMap(testMapArray);
    int startPt = -1;
    int endPt = 111;
    ASSERT_FALSE(testAstar->createNodeList(testMap,startPt, endPt));
}

TEST(AstarCreateNodeTest2, testCreateNodeForInBoundStartandEndPt) {
    Map testMap;
    testMap.storeMap(testMapArray);
    int startPt = 1;
    int endPt = 11;
    ASSERT_TRUE(testAstar->createNodeList(testMap,startPt, endPt));
}

TEST(AstarIdentifyNodeTest1, testIdentfyNodeForObstacleCoOrdinate) {
    ASSERT_EQ(testAstar->identifyNode(0,4),9999);
}

TEST(AstarIdentifyNodeTest2, testIdentfyNodeForNodeCoOrdinate) {
    ASSERT_EQ(testAstar->identifyNode(0,2),2);
}


