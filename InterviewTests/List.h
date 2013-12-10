//
//  List.h
//  InterviewPractice
//
//  Created by Stewart Bracken on 12/4/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#ifndef InterviewPractice_List_h
#define InterviewPractice_List_h



template <typename T>
class Node{
public:
    T data;
    Node<T>* next;
    Node(T _data):data(_data), next(NULL){
    }
};

template <typename T>
class List {
    
public:
    typedef Node<T> Node_t;
    Node_t* head;
    Node_t* tail;
    List():head(0),tail(0){}
    void insertBack(T data){
        Node_t* new_node =new Node_t(data);
        if(tail)
            tail->next = new_node;
        tail =  new_node;
        if(head == NULL){
            head = tail;
        }
    }
    void insertFront(T data){
        Node_t* tmp = new Node_t(data);
        tmp->next = head;
        if(head==NULL){tail = tmp; tmp->next=NULL;}
        head = tmp;
    }
    void insertFront(Node_t* other){
        this->insertFront(other->data);
    }
    ~List(){
        Node_t* curr = head;
        while(curr != NULL){
            head = curr->next;
            delete curr;
            curr = head;
        }
    }
};


typedef List<int> listi;
typedef Node<int> nodei;

#endif
