//
//  Split_unittest.cpp
//  InterviewTests
//
//  Created by Stewart Bracken on 12/7/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#include <stdio.h>
#include <algorithm> // for copy
#include <iterator> // for ostream_iterator

#include "Split.h"

#include <gtest/gtest.h>

using namespace std;


TEST(SPLITTEST, Split_delim){
    string s("what a snowy beautiful day.");
    vector<string> out = InterviewTest::split(s, ' ');
    vector<string> correct = {"what", "a", "snowy", "beautiful", "day."};
    EXPECT_TRUE(out==correct);
    copy(out.begin(), out.end(), ostream_iterator<string>(cout, " | "));
}

TEST(SPLITTEST, Split_letterdelim){
    string s("what a snowy beautiful day.");
    vector<string> out = InterviewTest::split(s, 'a');
    vector<string> correct = {"wh", "t ", " snowy be", "utiful d", "y."};
    EXPECT_TRUE(out==correct);
    copy(out.begin(), out.end(), ostream_iterator<string>(cout, " | "));
}