
//
//  abbreviate_sentence_unitttest.c
//  InterviewTests
//
//  Created by Stewart Bracken on 12/7/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#include <stdio.h>

#include "AbbreviateSentence.h"

#include <gtest/gtest.h>

TEST(AbbreviateSentence, AbbreviateSentence_test){
    string original("What a lonely night.");
    string expected("W2t a l4y n3t.");
    cout<< InterviewTest::AbbreviateSentence(original) <<endl;
}
