//
//  firstDuplicate.h
//  CppTests
//
//  Created by Stewart Bracken on 12/7/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#ifndef InterviewTests_firstDuplicate_h
#define InterviewTests_firstDuplicate_h

#include <unordered_set> //to find duplicates
#include <unordered_map>

// Returns the second itor of the first dup.
template <typename T>
typename std::vector<T>::const_iterator first_duplicate2(const std::vector<T>& data){
    std::unordered_set<T> unique_data;
    std::pair<typename std::unordered_set<T>::iterator, bool > insert_result;
    
    for( auto itor = data.cbegin(); itor != data.cend(); ++itor ){
        insert_result = unique_data.insert(*itor);
        
        //if set already contains *itor, return the first duplicate element
        if( !insert_result.second )
            return itor;
    }
    return data.end(); //not found
}


// Returns the first itor of the first dup.
template <typename T>
typename std::vector<T>::const_iterator first_duplicate(std::vector<T>& data){
    typedef typename std::vector<T>::iterator vec_itor_t;
    typedef std::unordered_map<T, vec_itor_t> unique_map_t;
    typedef typename std::unordered_map<T, vec_itor_t>::iterator unique_map_itor_t;
    typedef std::pair<T, vec_itor_t> unique_pair_t;
    
    unique_map_t unique_data;
    std::pair<unique_map_itor_t, bool > insert_result;
    
    for( vec_itor_t itor = data.begin(); itor != data.end(); ++itor ){
        insert_result = unique_data.insert(unique_pair_t(*itor, itor));
        
        //if set already contains *itor, return the first duplicate element
        if( !insert_result.second )
            //The insert result's first member is a unique_map_t itor.
            //Dereferencing to it's second member is the vec itor.
            return insert_result.first->second; // Uhg.
    }
    return data.end(); //not found
}

#endif
