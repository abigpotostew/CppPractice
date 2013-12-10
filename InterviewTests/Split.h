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

namespace InterviewTest{
    //only supports single delim character at this point
static vector<string> split(const string& toSplit, const char& delim){
    vector<string> out = vector<string>();
    string::const_iterator curr = toSplit.begin(),
                           prev = toSplit.begin(),
                           end = toSplit.end();
    int i=0;
    while( curr != end ){
        if ( strcmp( &delim, &(*curr) ) == 0 ) {
            curr++; //skip multiple delimiting characters in a row
            i++;
        }else{
            //curr points to non delim character
            prev = curr;
            int begin = i;
            while( curr != end ){ //look for next delim or end
                curr++;
                i++;
                //int cmp = strcmp( &delim, &(*curr) );
                if ( delim == *curr )
                    break;
                    
            }
            string subs = toSplit.substr( begin, i-begin );
            out.push_back(subs);
            if( curr != end ) { curr++; ++i; } //skip the last delim found
        }
    }
    return out;
}
}//namespace

#endif
