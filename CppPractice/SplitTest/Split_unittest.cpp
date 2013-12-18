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
    vector<string> out = split(s, ' ');
    vector<string> correct = {"what", "a", "snowy", "beautiful", "day."};
    copy(out.begin(), out.end(), ostream_iterator<string>(cout, " | "));
    ASSERT_TRUE(out==correct);
    
    out = split(s, 'a');
    correct = {"wh", "t ", " snowy be", "utiful d", "y."};
    copy(out.begin(), out.end(), ostream_iterator<string>(cout, " | "));
    ASSERT_TRUE(out==correct);
    
    s = "  spaces in front";
    out = split(s, ' ');
    correct = {"spaces", "in", "front"};
    copy(out.begin(), out.end(), ostream_iterator<string>(cout, " | "));
    ASSERT_TRUE(out==correct);
}

TEST(SPLITTEST, Split_split_index_only){
    string s("what a snowy beautiful day.");
    vector<string> out = split2(s, ' ');
    vector<string> correct = {"what", "a", "snowy", "beautiful", "day."};
    copy(out.begin(), out.end(), ostream_iterator<string>(cout, " | "));
    ASSERT_TRUE(out==correct);
    
    out = split2(s, 'a');
    correct = {"wh", "t ", " snowy be", "utiful d", "y."};
    copy(out.begin(), out.end(), ostream_iterator<string>(cout, " | "));
    ASSERT_TRUE(out==correct);
}