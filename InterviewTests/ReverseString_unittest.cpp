//
//  ReverseString_unittest.cpp
//  InterviewTests
//
//  Created by Stewart Bracken on 12/7/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#include <stdio.h>
#include <gtest/gtest.h>

#include "Split.h"

using namespace std;

TEST(ReverseString_unittest, ReverseString){
    string original("It's a snowy beautiful day!");
    string expected("day! beautiful snowy a It's");
    vector<string> split = InterviewTest::split(original, ' ');
    auto ritor = split.rbegin();
    string actual = *ritor;
    for( ++ritor; ritor != split.rend(); ++ritor){
        actual += " " + *ritor;
    }
    cout<< original << " -> " << actual <<endl;
    EXPECT_STREQ(expected.c_str(), actual.c_str());
}