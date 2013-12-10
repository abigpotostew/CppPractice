//
//  AbbreviateSentence.h
//  InterviewTests
//
//  Created by Stewart Bracken on 12/7/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#ifndef InterviewTests_AbbreviateSentence_h
#define InterviewTests_AbbreviateSentence_h

#include "Split.h"

namespace InterviewTest{
    string AbbreviateSentence(const string& sentence){
        vector<string> words = InterviewTest::split(sentence, ' ');
        string result = *(words[0].begin()) + string(words[0].size()+"") + *(words[0].rbegin());
        auto itor = words.begin();
        for( itor++; itor != words.end(); ++itor){
            //wrong, this needs to ignore puctuation
            result += &" " [ *(itor->begin())] + itor->size() + *(itor->rbegin());
        }
        return result;
    }
}

#endif
