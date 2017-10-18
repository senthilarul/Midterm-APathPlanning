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
 * @file      LayoutnodesTest.cpp
 * @author    Senthil Hariharan Arul
 * @copyright MIT License
 * @brief     Test cases for Class Layoutnodes
 */

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <Layoutnodes.hpp>
#include <memory>
#include <vector>

/**
 *@brief Case to test successful input of Layoutnodes parameters
 *@param none
 *@return none
 */ 
TEST(LayoutnodesSetNodeIndexTest, testNodeIndex) {
    std::shared_ptr<Layoutnodes> testNode = std::make_shared<Layoutnodes>();
    testNode->setNodeIndex(11, 4, 5);
    ASSERT_FLOAT_EQ(testNode->getIndex(), 11);
    ASSERT_FLOAT_EQ(testNode->getColumnIndex(), 4);
    ASSERT_FLOAT_EQ(testNode->getRowIndex(), 5);
}

/**
 *@brief Case to test successful parent index entry
 *@param none
 *@return none
 */
TEST(LayoutnodesSetParent, testParentIndex) {
    std::shared_ptr<Layoutnodes> testNode = std::make_shared<Layoutnodes>();
    testNode->setParentIndex(1);
    ASSERT_FLOAT_EQ(testNode->getParentIndex(), 1);
}

/**
 *@brief Case to test successful input of cost values
 *@param none
 *@return none
 */
TEST(LayoutnodesSetCost, testCost) {
    std::shared_ptr<Layoutnodes> testNode = std::make_shared<Layoutnodes>();
    testNode->setHeuristicCost(1.3);
    testNode->setPathCost(1.5);
    testNode->setTotalCost();
    ASSERT_FLOAT_EQ(testNode->getCost(), 1.63);
}

