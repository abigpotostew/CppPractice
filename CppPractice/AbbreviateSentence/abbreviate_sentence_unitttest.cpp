
//
//  abbreviate_sentence_unitttest.c
//  CppTests
//
//  Created by Stewart Bracken on 12/7/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#include <stdio.h>

#include "AbbreviateSentence.h"

#include <gtest/gtest.h>

TEST(AbbreviateSentence, AbbreviateSentence_test){
    std::string original("What a night.");
    std::string expected("W2t a n3t.");
    std::cout<< AbbreviateSentence(original) << std::endl;
}
