//
//  BinaryChop.cpp
//  CppTests
//
//  Created by Stewart Bracken on 12/8/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#include <stdio.h>
#include <vector>

#include "BinaryChop.h"

#include "MathUtil.h"

//iterative approach
int BinaryChop::chop1(int to_find, const std::vector<int>& data){
    int len = static_cast<int>(data.size()),
        low = 0;
    if(len == 0) return NOT_FOUND;
    int i;
    int curr_data;
    
    while( len > 0 ){//&& low < data.size()
        i = len/2 + low;
        curr_data = data[i];
        if( curr_data == to_find ){
            return i;
        }else if( to_find > curr_data ){
            //Need to search farther down array
            low = i+1;
            len = (len-1)/2;
        }else{ //to_find < curr_data
            //Search again at a smaller index.
            len = div_ceil( len-1, 2 );
        }
    }
    return NOT_FOUND;
}

//This is tail recursive
static int chop2_rec(int& to_find, const std::vector<int>& data,
                     int& length, int& low){
    if(length == 0)
        return NOT_FOUND;
    int i = length/2 + low;
    int curr_data = data[i];
    if( curr_data == to_find ){
        return i;
    }else if( to_find > curr_data ){
        low = i+1;
        length = (length-1)/2;
    }else{
        length = div_ceil(length-1, 2);
    }
    return chop2_rec(to_find, data, length, low);
}

int BinaryChop::chop2(int to_find, const std::vector<int>& data){
    int length = static_cast<int>(data.size());
    int low = 0;
    return chop2_rec(to_find, data, length, low);
}