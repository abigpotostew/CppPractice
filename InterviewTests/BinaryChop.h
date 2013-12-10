//
//  BinaryChop.h
//  InterviewTests
//
//  Created by Stewart Bracken on 12/8/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#ifndef InterviewTests_BinaryChop_h
#define InterviewTests_BinaryChop_h

#include <vector>

#define NOT_FOUND -1

namespace BinaryChop {
    //These all should return the same value if supplied equivalent args
    int chop1(int to_find, std::vector<int>& data);
}

#endif
