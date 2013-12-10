//
//  ListKTest_unittest.cpp
//  InterviewPractice
//
//  Created by Stewart Bracken on 12/5/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#include <stdio.h>

#include <gtest/gtest.h>
#include "List.h"
#include "ListKTest.hpp"


TEST(ListKTest, SkipKReverseK){
    List<int> list;
    for(int i = 0; i < 20; ++i){
        list.insertBack(i+1);
    }
    printList(list);
    reverseKList(list, 20);
    printList(list);
}
