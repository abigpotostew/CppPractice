 //
//  BinaryChop_unitttest.cpp
//  InterviewTests
//
//  Created by Stewart Bracken on 12/9/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <gtest/gtest.h>
#include "BinaryChop.h"
using namespace std;
TEST(BinaryChop, Chop_iterative){
    vector<int> data = {  };
    ASSERT_TRUE(NOT_FOUND == BinaryChop::chop1(3, data));
    data = {1};
    ASSERT_TRUE(NOT_FOUND == BinaryChop::chop1(3, data));
    ASSERT_TRUE(0 == BinaryChop::chop1(1, data));
    
    data = {1, 3, 5};
    ASSERT_TRUE(0 == BinaryChop::chop1(1, data));
    ASSERT_TRUE(1 == BinaryChop::chop1(3, data));
    ASSERT_TRUE(2 == BinaryChop::chop1(5, data));
    ASSERT_TRUE(NOT_FOUND == BinaryChop::chop1(0, data));
    ASSERT_TRUE(NOT_FOUND == BinaryChop::chop1(2, data));
    ASSERT_TRUE(NOT_FOUND == BinaryChop::chop1(4, data));
    ASSERT_TRUE(NOT_FOUND == BinaryChop::chop1(6, data));
    
    data = {1, 3, 5, 7};
    ASSERT_TRUE(0 == BinaryChop::chop1(1, data));
    ASSERT_TRUE(1 == BinaryChop::chop1(3, data));
    ASSERT_TRUE(2 == BinaryChop::chop1(5, data));
    ASSERT_TRUE(3 == BinaryChop::chop1(7, data));
}
