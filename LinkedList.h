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

Node* head = NULL;
Node* tail = NULL;

Node* LinkedList_initializeNode(const char* data, Node* next, Node* previous);
void LinkedList_push_front(const char* value);
void LinkedList_push_back(const char* value);
void LinkedList_pop_front(void);
void LinkedList_pop_back(void);
char* LinkedList_front(void);
char* LinkedList_back(void);
int LinkedList_is_empty(void);
void LinkedList_remove_value(const char* value);
void LinkedList_clear(void);
void LinkedList_reverse(void);
size_t LinkedList_size(void);
char* LinkedList_toString(void);




#endif //LAB_03_LINKED_LIST_LINKEDLIST_H
