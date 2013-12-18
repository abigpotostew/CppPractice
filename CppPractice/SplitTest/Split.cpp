//
//  Split.cpp
//  InterviewPractice
//
//  Created by Stewart Bracken on 12/5/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#include "Split.h"

using namespace std;

//Using iterator access and the std::distance function
vector<string> split(const string& toSplit, const char& delim){
    vector<string> out = vector<string>();
    string::const_iterator curr = toSplit.begin(),
                           begin = toSplit.begin(),
                           end = toSplit.end();
    while( curr != end ){
        if ( delim == *curr ) {
            curr++; //skip multiple delimiting characters in a row
        }else{
            //curr points to non delim character
            //int begin = i;
            string::const_iterator prev = curr;
            while( curr != end ){ //look for next delim or end
                curr++;
                if ( delim == *curr )
                    break;
            }
            string subs = toSplit.substr( std::distance(begin, prev), std::distance(prev, curr));
            out.push_back(subs);
            if( curr != end ) {
                curr++; //skip the last delim found
            }
        }
    }
    return out;
}

//using random access iteration.
vector<string> split2(const string& toSplit, const char& delim){
    vector<string> out = vector<string>();
    //string::const_iterator curr = toSplit.begin(),
    //end = toSplit.end();
    size_t i = 0,
           endi = toSplit.size();
    //int i=0;
    while( i != endi ){
        if ( strcmp( &delim, &(toSplit[i]) ) == 0 ) {
            //curr++; //skip multiple delimiting characters in a row
            i++;
        }else{
            //curr points to non delim character
            size_t begin = i;
            while( i != endi ){ //look for next delim or end
                i++;
                if ( delim == toSplit[i] )
                    break;
            }
            string subs = toSplit.substr( begin, i-begin );
            out.push_back(subs);
            if( i != endi ) {
                ++i; //skip the last delim found
            }
        }
    }
    return out;
}

//TODO write split entirly in a single loop