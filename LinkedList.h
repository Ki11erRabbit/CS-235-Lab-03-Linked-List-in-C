//
// Created by ki11errabbit on 6/6/22.
//

#ifndef LAB_03_LINKED_LIST_LINKEDLIST_H
#define LAB_03_LINKED_LIST_LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node{
    char* data;
    struct Node* next;
    struct Node* previous;
} Node;

typedef struct Linked_List {
    Node* head;
    Node* tail;
} Linked_List;

Linked_List* LinkedList_Linked_List();
Node* LinkedList_initializeNode(const char* data, Node* next, Node* previous);
void LinkedList_push_front(Linked_List* this,const char* value);
void LinkedList_push_back(Linked_List* this,const char* value);
void LinkedList_pop_front(Linked_List* this);
void LinkedList_pop_back(Linked_List* this);
char* LinkedList_front(Linked_List* this);
char* LinkedList_back(Linked_List* this);
int LinkedList_is_empty(Linked_List* this);
void LinkedList_remove_value(Linked_List* this,const char* value);
void LinkedList_clear(Linked_List* this);
void LinkedList_reverse(Linked_List* this);
size_t LinkedList_size(Linked_List* this);
void LinkedList_output_list(Linked_List* this);
char* LinkedList_toString(Linked_List* this);




#endif //LAB_03_LINKED_LIST_LINKEDLIST_H
