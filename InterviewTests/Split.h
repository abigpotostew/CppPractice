//
//  Split.h
//  InterviewPractice
//
//  Created by Stewart Bracken on 12/5/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#ifndef InterviewPractice_Split_h
#define InterviewPractice_Split_h

#include <vector>
#include <string>

using namespace std;

//only supports single delim character at this point
vector<string> split(const string& toSplit, const char& delim);
vector<string> split2(const string& toSplit, const char& delim);

#endif
