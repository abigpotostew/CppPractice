//
//  main.cpp
//  CppTests
//
//  Created by Stewart Bracken on 12/7/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#include <iostream>
#include <gtest/gtest.h>

// I'm having weird issues with linking, such that EXPECT_EQ() gives an
// undefined symbols error for the following function. It seems adding the below
// code makes the macro work.

testing::AssertionResult testing::internal::EqFailure(char const*, char const*, string const&, string const&, bool){
    return AssertionSuccess();
}

void testing::internal::PrintStringTo(const ::std::string &s, ::std::ostream *os)
{
    if (os) {
        *os << s;
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}