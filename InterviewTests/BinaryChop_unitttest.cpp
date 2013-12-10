 //
//  BinaryChop_unitttest.cpp
//  CppTests
//
//  Created by Stewart Bracken on 12/9/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <gtest/gtest.h>
#include "BinaryChop.h"

typedef int (*chop_ptr)(int, const std::vector<int>&);

TEST(BinaryChop, Chop_iterative){
    //Use point because it's easier to copy paste test data
    chop_ptr chop = &(BinaryChop::chop1);
    
    std::vector<int> data = {  };
    ASSERT_EQ( NOT_FOUND, chop(3, data));
    data = {1};
    ASSERT_EQ(NOT_FOUND, chop(3, data));
    ASSERT_EQ(0, chop(1, data));
    
    data = {1, 3, 5};
    ASSERT_EQ(0, chop(1, data));
    ASSERT_EQ(1, chop(3, data));
    ASSERT_EQ(2, chop(5, data));
    ASSERT_EQ(NOT_FOUND, chop(0, data));
    ASSERT_EQ(NOT_FOUND, chop(2, data));
    ASSERT_EQ(NOT_FOUND, chop(4, data));
    ASSERT_EQ(NOT_FOUND, chop(6, data));
    
    data = {1, 3, 5, 7};
    ASSERT_EQ(0, chop(1, data));
    ASSERT_EQ(1, chop(3, data));
    ASSERT_EQ(2, chop(5, data));
    ASSERT_EQ(3, chop(7, data));
    ASSERT_EQ(NOT_FOUND, chop(0, data));
    ASSERT_EQ(NOT_FOUND, chop(2, data));
    ASSERT_EQ(NOT_FOUND, chop(4, data));
    ASSERT_EQ(NOT_FOUND, chop(6, data));
    ASSERT_EQ(NOT_FOUND, chop(8, data));
    
    for(int i = 0; i < 500; ++i){
        data.push_back(i*2 + 9);
    }
    ASSERT_EQ(250, chop(501, data));
    ASSERT_EQ(500, chop(1001, data));
    ASSERT_EQ(NOT_FOUND, chop(1000000, data));
}

TEST(BinaryChop, Chop_recursive){
    chop_ptr chop = &BinaryChop::chop2;
    
    std::vector<int> data = {  };
    ASSERT_EQ(NOT_FOUND, chop(3, data));
    
    data = {1};
    ASSERT_EQ(NOT_FOUND, chop(3, data));
    ASSERT_EQ(0, chop(1, data));
    
    data = {1, 3, 5};
    ASSERT_EQ(0, chop(1, data));
    ASSERT_EQ(1, chop(3, data));
    ASSERT_EQ(2, chop(5, data));
    ASSERT_EQ(NOT_FOUND, chop(0, data));
    ASSERT_EQ(NOT_FOUND, chop(2, data));
    ASSERT_EQ(NOT_FOUND, chop(4, data));
    ASSERT_EQ(NOT_FOUND, chop(6, data));
    
    data = {1, 3, 5, 7};
    ASSERT_EQ(0, chop(1, data));
    ASSERT_EQ(1, chop(3, data));
    ASSERT_EQ(2, chop(5, data));
    ASSERT_EQ(3, chop(7, data));
    ASSERT_EQ(NOT_FOUND, chop(0, data));
    ASSERT_EQ(NOT_FOUND, chop(2, data));
    ASSERT_EQ(NOT_FOUND, chop(4, data));
    ASSERT_EQ(NOT_FOUND, chop(6, data));
    ASSERT_EQ(NOT_FOUND, chop(8, data));
    
    for(int i = 0; i < 500; ++i){
        data.push_back(i*2 + 9);
    }
    ASSERT_EQ(250, chop(501, data));
    ASSERT_EQ(500, chop(1001, data));
    ASSERT_EQ(NOT_FOUND, chop(1000000, data));
}
