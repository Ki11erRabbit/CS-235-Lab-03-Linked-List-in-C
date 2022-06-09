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
    void (*deconstruct)(struct Linked_List*);
    struct Linked_List* (*clone)(struct Linked_List*);
    void (*push_front)(struct Linked_List*, char*);
    void (*push_back)(struct Linked_List*, char*);
    void (*pop_front)(struct Linked_List*);
    void (*pop_back)(struct Linked_List*);
    char* (*front)(struct Linked_List*);
    char* (*back)(struct Linked_List*);
    int (*empty)(struct Linked_List*);
    size_t (*size)(struct Linked_List*);
    void (*remove)(struct Linked_List*, char*);
    void (*reverse)(struct Linked_List*);
    void (*clear)(struct Linked_List*);
    void (*print)(struct Linked_List*);

} Linked_List;

Linked_List* LinkedList_Linked_List();//constructor
void LinkedList_Deconstruct(Linked_List* self);//Deconstructor
Linked_List* LinkedList_Copy(Linked_List* self);//
Node* LinkedList_initializeNode(const char* data, Node* next, Node* previous);
void LinkedList_push_front(Linked_List* self,const char* value);
void LinkedList_push_back(Linked_List* self,const char* value);
void LinkedList_pop_front(Linked_List* self);
void LinkedList_pop_back(Linked_List* self);
char* LinkedList_front(Linked_List* self);
char* LinkedList_back(Linked_List* self);
int LinkedList_is_empty(Linked_List* self);
void LinkedList_remove_value(Linked_List* self,const char* value);
void LinkedList_clear(Linked_List* self);
void LinkedList_reverse(Linked_List* self);
size_t LinkedList_size(Linked_List* self);
void LinkedList_output_list(Linked_List* self);
char* LinkedList_toString(Linked_List* self);




#endif //LAB_03_LINKED_LIST_LINKEDLIST_H
