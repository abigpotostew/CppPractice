//
//  FirstDuplicate_unittest.cpp
//  CppTests
//
//  Created by Stewart Bracken on 12/7/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <gtest/gtest.h>
#include "duplicate.h"

TEST(FirstDuplicate_unittest, FirstDup){
    std::vector<int> original = { 4, 3, 1, 2, 5, 9, 5, 4 };
    int expected = 5;
    int actual = *( first_duplicate( original ) );
    std::cout<< "First duplicate: " << actual << std::endl;
    EXPECT_EQ(expected, actual);
    
    std::vector<int>::iterator second_actual_dup = original.begin();
    bool hit_first_5= false;
    while(true){
        second_actual_dup++;
        if(*second_actual_dup == 5){
            if (hit_first_5) {
                break;
            }else{
                hit_first_5 = true;
            }
        }
    }
    
    EXPECT_TRUE(second_actual_dup == first_duplicate2( original ) );
    
    std::vector<int>::const_iterator first_actual_dup = first_duplicate(original);
    EXPECT_TRUE(std::distance(original.begin(),second_actual_dup)
                !=
                std::distance(original.cbegin(),first_actual_dup));
}