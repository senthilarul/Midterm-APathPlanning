#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Layoutnodes.hpp>
#include <memory>

TEST(LayoutnodesSetNodeIndexTest, testNodeIndex) {
    std::shared_ptr<Layoutnodes> testNode = std::make_shared<Layoutnodes>();
    testNode->setNodeIndex(11,4,5);
    ASSERT_FLOAT_EQ(testNode->getIndex(), 11);
    ASSERT_FLOAT_EQ(testNode->getColumnIndex(), 4);
    ASSERT_FLOAT_EQ(testNode->getRowIndex(), 5);
}

TEST(LayoutnodesSetParent, testParentIndex) {
    std::shared_ptr<Layoutnodes> testNode = std::make_shared<Layoutnodes>();
    testNode->setParentIndex(1);
    ASSERT_FLOAT_EQ(testNode->getParentIndex(),1);
}

TEST(LayoutnodesSetCost, testCost) {
    std::shared_ptr<Layoutnodes> testNode = std::make_shared<Layoutnodes>();
    testNode->setHeuristicCost(1.3);
    testNode->setPathCost(1.5);
    testNode->setTotalCost();
    ASSERT_FLOAT_EQ(testNode->getCost(),1.63);
}

