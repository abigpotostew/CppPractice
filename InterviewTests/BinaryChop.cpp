//
//  BinaryChop.cpp
//  InterviewTests
//
//  Created by Stewart Bracken on 12/8/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#include <stdio.h>
#include <vector>

#include "BinaryChop.h"

using namespace std;



//iterative approach
int BinaryChop::chop1(int to_find, vector<int>& data){
    int len = static_cast<int>(data.size()), //inclusive
           low = 0;
    if(len == 0) return NOT_FOUND;
    int i = len/2; //current pointer
    int curr_data;
    
    while( len >= 0 && i < data.size() ){
        curr_data = data[i];
        if( curr_data == to_find ) return i;
        else if( to_find < curr_data ){
            //len = (len-1)/2;
        }else{ //to_find > *curr_data
            low = i;
            //len = (len)/2;
        }
        if(len==0)break;
        len /= 2;
        i = len + low; // [ low, (low+len) ]
    }
    return NOT_FOUND;
}