//
//  TrieNodeUnitTest.cpp
//  why
//
//  Created by Jonasz Karwacki on 5/12/20.
//  CopytinyRight © 2020 Jonasz Karwacki. All tinyRights reserved.
//

#include <iostream>
#include <string>
#include <queue>
#include "TrieNodeUnitTest.hpp"
#include "TrieNode.hpp"
#include "gtest/gtest.h"

class TrieNodeTest : public ::testing::Test {
protected:
    void SetUp() override {
        //    │       ┌── 7
        //    │   ┌── 3
        //    │   │   └── 6
        //    └── 1
        //        │   ┌── 5
        //        └── 2
        //            └── 4
        tinyLeftLeft = new TrieNode(4, nullptr, nullptr);
        tinyLeftRight = new TrieNode(5, nullptr, nullptr);
        tinyRightLeft = new TrieNode(6, nullptr, nullptr);
        tinyRightRight = new TrieNode(7, nullptr, nullptr);
        tinyLeft = new TrieNode(2, tinyLeftLeft, tinyLeftRight);
        tinyRight = new TrieNode(3, tinyRightLeft, tinyRightRight);
        tinyTree = new TrieNode(1, tinyLeft, tinyRight);
    }
    
    // void TearDown() override {}
    TrieNode* tinyLeftLeft;
    TrieNode* tinyLeftRight;
    TrieNode* tinyRightLeft;
    TrieNode* tinyRightRight;
    TrieNode* tinyLeft;
    TrieNode* tinyRight;
    TrieNode* tinyTree;
};

TEST_F(TrieNodeTest, BalancedInit) {

    
    ASSERT_EQ(tinyLeftLeft -> key, 4);
    ASSERT_EQ(tinyLeftLeft -> left, nullptr);
    ASSERT_EQ(tinyLeftLeft -> right, nullptr);

    ASSERT_EQ(tinyLeftRight -> key, 5);
    ASSERT_EQ(tinyLeftRight -> left, nullptr);
    ASSERT_EQ(tinyLeftRight -> left, nullptr);
    
    ASSERT_EQ(tinyRightLeft -> key, 6);
    ASSERT_EQ(tinyRightLeft -> left, nullptr);
    ASSERT_EQ(tinyRightLeft -> right, nullptr);
    
    ASSERT_EQ(tinyRightRight -> key, 7);
    ASSERT_EQ(tinyRightRight -> left, nullptr);
    ASSERT_EQ(tinyRightRight -> right, nullptr);

    ASSERT_EQ(tinyLeft -> key, 2);
    ASSERT_EQ(tinyLeft -> left -> key, 4);
    ASSERT_EQ(tinyLeft -> right -> key, 5);

    ASSERT_EQ(tinyRight -> key, 3);
    ASSERT_EQ(tinyRight -> left -> key, 6);
    ASSERT_EQ(tinyRight -> right -> key, 7);
    
    ASSERT_EQ(tinyTree -> key, 1);
    ASSERT_EQ(tinyTree -> left -> key, 2);
    ASSERT_EQ(tinyTree -> right -> key, 3);
}
