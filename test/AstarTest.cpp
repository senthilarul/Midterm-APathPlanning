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
 * @file      AstarTest.cpp
 * @author    Senthil Hariharan Arul
 * @copyright MIT License
 * @brief     Test cases for class Astar
 */

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include "Astar.hpp"
#include <vector>

std::shared_ptr<Astar> testAstar = std::make_shared<Astar>();
std::vector<int> testMapArray {1, 1, 1, 1, 0, 1, 0,
                               0, 0, 0, 1, 1, 0, 0,
                               0, 0, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 0};
/**
 *@brief Case to test for out of bound start and end point
 *@param none
 *@return none
 */
TEST(AstarCreateNodeTest1, testCreateNodeForOutOfBoundStartandEndPt) {
    Map testMap;
    testMap.storeMap(testMapArray);
    int startPt = -1;
    int endPt = 111;
    ASSERT_FALSE(testAstar->createNodeList(testMap, startPt, endPt));
}

/**
 *@brief Case to test successful working for inrange
 *       start and end point
 *@param none
 *@return none
 */
TEST(AstarCreateNodeTest2, testCreateNodeForInBoundStartandEndPt) {
    Map testMap;
    testMap.storeMap(testMapArray);
    int startPt = 1;
    int endPt = 11;
    ASSERT_TRUE(testAstar->createNodeList(testMap, startPt, endPt));
}

/**
 *@brief Case to test for removal of obstacle coordinate
 *@param none
 *@return none
 */
TEST(AstarIdentifyNodeTest1, testIdentfyNodeForObstacleCoOrdinate) {
    ASSERT_EQ(testAstar->identifyNode(0, 4), 9999);
}

/**
 *@brief Case to test for successful identification of nodeindex
 *       from node coordinates.
 *@param none
 *@return none
 */
TEST(AstarIdentifyNodeTest2, testIdentfyNodeForNodeCoOrdinate) {
    ASSERT_EQ(testAstar->identifyNode(0, 2), 2);
}

/**
 *@brief Case to test successful calculation of shortest path
 *@param none
 *@return none
 */
TEST(AstarPlanPathTest, testShortestPathForKnownMap) {
    Map testMap;
    testMap.storeMap(testMapArray);
    testAstar->setStartPoint(2);
    testAstar->setEndPoint(17);
    ASSERT_EQ(testAstar->planPath(), 6);
}

