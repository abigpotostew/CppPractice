//
//  BinaryChop.h
//  CppTests
//
//  Created by Stewart Bracken on 12/8/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#ifndef InterviewTests_BinaryChop_h
#define InterviewTests_BinaryChop_h

#include <vector>

#define NOT_FOUND -1

//These all should return the same value if supplied equivalent args
namespace BinaryChop {
    //Iterative
    int chop1(int to_find, const std::vector<int>& data);
    //Tail Recursive
    int chop2(int to_find, const std::vector<int>& data);
    //vector slicing
    int chop3(int to_find, const std::vector<int>& data);
    //concurrent searching
    int chop4(int to_find, const std::vector<int>& data);
}

#endif
