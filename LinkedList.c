//
// Created by ki11errabbit on 6/6/22.
//

#include "LinkedList.h"


Linked_List* LinkedList_Linked_List() {
    Linked_List* newList;
    newList = malloc(sizeof(Linked_List));
    newList->head = NULL;
    newList->tail = NULL;
    return newList;
}

void LinkedList_Deconstruct(Linked_List* this) {
    if (this == NULL) return;//In case the object pointer has not yet been initialized
    if (this->head != NULL) {//copied from clear() to not have output;
        Node* currNode = this->head;
        while (currNode != NULL) {
            Node* nextNode = currNode->next;
            free(currNode->data);
            currNode->data = NULL;
            free(currNode);
            currNode = nextNode;
        }
        this->head = NULL;
        this->tail = NULL;
    }
    else {
    }

    free(this);
}
Linked_List* LinkedList_Copy(Linked_List* this) {
    Linked_List* newList = NULL;
    newList = malloc(sizeof(Linked_List));
    newList->head = NULL;
    newList->tail = NULL;

    if (this->head != NULL) {
        Node* currNode = this->head;
        while (currNode != NULL) {
            Node* nextNode = currNode->next;
            //printf("%s ", currNode->data);
            LinkedList_push_back(newList, strdup(currNode->data));
            currNode = nextNode;
        }
        //printf("\n");
    }
    else {
        printf("Empty\n");
    }

    return newList;
}

Node* LinkedList_initializeNode(const char* data, Node* next, Node* previous) {
    Node* tempNode;
    tempNode = malloc(sizeof(Node));
    tempNode->data = data;
    tempNode->next = next;
    tempNode->previous = previous;
    return tempNode;
}

void LinkedList_clear(Linked_List* this) {
    if (this->head != NULL) {
        Node* currNode = this->head;
        while (currNode != NULL) {
            Node* nextNode = currNode->next;
            free(currNode->data);
            currNode->data = NULL;
            free(currNode);
            currNode = nextNode;
        }
        this->head = NULL;
        this->tail = NULL;
        printf("Ok");
    }
    else {
        printf("There are no nodes");
    }
}

void LinkedList_push_front(Linked_List* this, const char* value) {
    Node* newNode = LinkedList_initializeNode(value, this->head, NULL);

    if (LinkedList_size(this) == 0) {
        this->tail = newNode;
    }
    else {
        this->head->previous = newNode;
    }
    this->head = newNode;
}
void LinkedList_push_back(Linked_List* this, const char* value) {
    Node* newNode = LinkedList_initializeNode(value, NULL, this->tail);
    if (LinkedList_size(this) == 0) {
        this->head = newNode;
    }
    else {
        this->tail->next = newNode;
    }
    this->tail = newNode;
}

void LinkedList_pop_front(Linked_List* this) {
    if (this->head == NULL) {
        printf("Empty Linked List!");
        return;
    }
    Node* newHead = this->head->next;
    if (newHead == NULL) {
        this->tail=NULL;
    }
    else {
        newHead->previous = NULL;
    }

    free(this->head->data);
    this->head->data = NULL;
    free(this->head);
    this->head = newHead;
}
void LinkedList_pop_back(Linked_List* this) {
    if (this->tail == NULL) {
        printf("Empty Linked List!");
        return;
    }
    Node* newTail = this->tail->previous;
    if (newTail == NULL) {
        this->head = NULL;
    }
    else {
        newTail->next = NULL;
    }
    free(this->tail->data);
    this->tail->data = NULL;
    free(this->tail);
    this->tail = newTail;
}

char* LinkedList_front(Linked_List* this) {
    if (this->head == NULL) {
        //printf("Error! Empty Linked List!");
        return "Empty!";
    } else {
        return this->head->data;
    }
}
char* LinkedList_back(Linked_List* this) {
    if (this->tail == NULL) {
        //printf("Error! Empty Linked List!");
        return "Empty!";
    } else {
        return this->tail->data;
    }
}

int LinkedList_is_empty(Linked_List* this) {
    if (this->head == NULL && this->tail == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}
void LinkedList_remove_value(Linked_List* this, const char* value) {
    if (this->head == NULL) {
        printf("Error! Linked List Empty!");
    }
    else {
        Node* currNode = this->head;
        while (currNode != NULL) {
            if (strcmp(currNode->data,value) == 0 && currNode == this->head) {
                LinkedList_pop_front(this);
                currNode = this->head;
            }
            else if (strcmp(currNode->data, value) == 0) {
                Node* nextNode = currNode->next;
                Node* previousNode = currNode->previous;
                free(currNode->data);
                currNode->data = NULL;
                free(currNode);
                currNode = nextNode;
                previousNode->next = nextNode;
                if (nextNode != NULL) {
                    nextNode->previous = previousNode;
                }
                else {
                    currNode = NULL;
                    this->tail = previousNode;
                }

            }
            else {
                currNode = currNode->next;
            }
        }
        if (LinkedList_size(this) == 0) {
            this->head = NULL;
            this->tail = NULL;
        }
    }
}

void LinkedList_reverse(Linked_List* this) {

    if (this->head == NULL) {
        printf("Error! Empty Linked List!\n");
        return;
    }
    Node* currNode = this->head;
    while (currNode != NULL) {
        Node* temp = currNode->next;
        currNode->next = currNode->previous;
        currNode->previous = temp;

        currNode = temp;
    }
    Node* temp = this->tail;
    this->tail = this->head;
    this->head = temp;
}

size_t LinkedList_size(Linked_List* this) {
    Node* currNode = this->head;
    size_t count = 0;
    while (currNode != NULL) {
        count++;
        currNode = currNode->next;
    }
    return count;
}

void LinkedList_output_list(Linked_List* this) {
    if (this->head != NULL) {
        Node* currNode = this->head;
        while (currNode != NULL) {
            Node* nextNode = currNode->next;
            printf("%s ", currNode->data);
            currNode = nextNode;
        }
        printf("\n");
    }
    else {
        printf("Empty\n");
    }
}

char* LinkedList_toString(Linked_List* this);