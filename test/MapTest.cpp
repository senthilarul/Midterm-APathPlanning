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
 * @file      MapTest.cpp
 * @author    Senthil Hariharan Arul
 * @copyright MIT License
 * @brief     Test Cases for Class Map
 */

#include <gtest/gtest.h>
#include <memory>
#include "Map.hpp"

std::shared_ptr<Map> testMap = std::make_shared<Map>();
std::vector<int> testMapArray1 {1, 1, 1, 1, 0, 0, 0, 0,
                                0, 0, 0, 1, 1, 0, 0, 0,
                                0, 0, 1, 1, 1, 1, 1, 0,
                                1, 1, 1, 1, 1, 1, 1, 0};
/**
 *@brief Case to test successful generation of map from
 *       input .csv file
 *@param none
 *@return none
 */
TEST(MapLoadMapTest1, testLoadMapMethodWithDefaultMap) {
    testMap->loadMap("../Data/data1.csv");
    ASSERT_EQ(testMap->returnColumn(), 8);
    ASSERT_EQ(testMap->returnRow(), 4);
    ASSERT_EQ(testMap->getMap(), testMapArray1);
}
/**
 *@brief Case to test error message for wrong .csv file
 *@param none
 *@return none
 */
TEST(MapLoadMapTest2, testLoadMapMethodWithWrongMap) {
    std::shared_ptr<Map> testMap1 = std::make_shared<Map>();
    testMap1->loadMap("unknown.csv");
    ASSERT_EQ(testMap1->returnColumn(), 0);
    ASSERT_EQ(testMap1->returnRow(), 0);
}
