//
//  ListKTest.cpp
//  InterviewPractice
//
//  Created by Stewart Bracken on 12/5/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include "List.h"


using namespace std;

void printList(listi& list){
    for( nodei* itor = list.head; itor != 0; itor = itor->next){
        cout<< itor->data << ", ";
    }
    cout<<endl;
}

void reverseKList(listi& list, int k){
    nodei* curr = list.head;
    nodei* tmp;
    while(curr!=NULL){
        //skip k node
        for(int i=0; i<k && curr != NULL; ++i){
            curr = curr->next;
        }
        //reverse k nodes
        tmp = curr;
        listi reverse;
        for(int i=0; i<k && curr != NULL; ++i){
            reverse.insertFront(curr);
            curr = curr->next;
        }
        //printList(reverse);
        curr = tmp;
        tmp = reverse.head;
        for(int i=0; i<k && tmp != NULL; ++i){
            curr->data = tmp->data;
            curr = curr->next;
            tmp = tmp->next;
        }
    }
}