//
//  ReverseString_unittest.cpp
//  CppTests
//
//  Created by Stewart Bracken on 12/7/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#include <stdio.h>
#include <gtest/gtest.h>

#include "Split.h"

TEST(ReverseString_unittest, ReverseString){
    std::string original("It's a snowy beautiful day!");
    std::string expected("day! beautiful snowy a It's");
    std::vector<string> s = split(original, ' ');
    auto ritor = s.rbegin();
    std::string actual = *ritor;
    for( ++ritor; ritor != s.rend(); ++ritor){
        actual += " " + *ritor;
    }
    std::cout<< original << " -> " << actual << std::endl;
    EXPECT_STREQ(expected.c_str(), actual.c_str());
}