//
//  FirstDuplicate_unittest.cpp
//  InterviewTests
//
//  Created by Stewart Bracken on 12/7/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <gtest/gtest.h>
#include "firstDuplicate.h"

using namespace std;

TEST(FirstDuplicate_unittest, FirstDup){
    vector<int> original = { 4, 3, 1, 2, 5, 9, 5, 4 };
    int expected = 5;
    int actual = *Duplicate::first_duplicate(original);
    cout<< "First duplicate: " << actual << endl;
    EXPECT_TRUE(expected == actual);
}