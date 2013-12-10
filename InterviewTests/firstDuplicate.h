//
//  firstDuplicate.h
//  InterviewTests
//
//  Created by Stewart Bracken on 12/7/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#ifndef InterviewTests_firstDuplicate_h
#define InterviewTests_firstDuplicate_h

#include <unordered_set>
using namespace std;

namespace Duplicate {
    template <typename T>
    typename vector<T>::const_iterator first_duplicate(const vector<T>& data){
        //find smallest distance between duplicates
        //require a fast way to find duplicates
        unordered_set<T> unique_data;
        pair<typename unordered_set<T>::iterator, bool > insert_result;
        for(typename vector<T>::const_iterator itor = data.begin(); itor != data.end(); ++itor){
            insert_result = unique_data.insert(*itor);
            if( !insert_result.second )
                return itor;
        }
        return data.end();
    }
}

#endif
