//
// Created by ki11errabbit on 6/6/22.
//

#include "LinkedList.h"

Node* head = NULL;
Node* tail = NULL;

Node* LinkedList_initializeNode(const char* data, Node* next, Node* previous) {
    Node* tempNode;
    tempNode = malloc(sizeof(Node));
    tempNode->data = data;
    tempNode->next = next;
    tempNode->previous = previous;
    return tempNode;
}

void LinkedList_clear(void) {
    if (head != NULL) {
        Node* currNode = head;
        while (currNode != NULL) {
            Node* nextNode = currNode->next;
            free(currNode->data);
            free(currNode);
            currNode = nextNode;
        }
        head = NULL;
        tail = NULL;
        printf("Ok");
    }
    else {
        printf("There are no nodes");
    }
}

void LinkedList_push_front(const char* value) {
    head = LinkedList_initializeNode(value, head, NULL);
}
void LinkedList_push_back(const char* value) {
    tail = LinkedList_initializeNode(value, NULL, tail);
}

void LinkedList_pop_front(void) {
    if (head == NULL) {
        printf("Empty Linked List!");
        return;
    }
    Node* newHead = head->next;
    free(head->data);
    free(head);
    head = newHead;
}
void LinkedList_pop_back(void) {
    if (tail == NULL) {
        printf("Empty Linked List!");
        return;
    }
    Node* newTail = tail->previous;
    free(tail->data);
    free(tail);
    tail = newTail;
}

char* LinkedList_front(void) {
    if (head == NULL) {
        printf("Error! Empty Linked List!");
        return strdup("Error");
    } else {
        return head->data;
    }
}
char* LinkedList_back(void) {
    if (tail == NULL) {
        printf("Error! Empty Linked List!");
        return strdup("Error");
    } else {
        return tail->data;
    }
}

int LinkedList_is_empty(void) {
    if (head == NULL && tail == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}
void LinkedList_remove_value(const char* value) {
    if (head == NULL) {
        printf("Error! Linked List Empty!");
    }
    else {
        Node* currNode = head;
        while (currNode != NULL) {
            if (strcmp(currNode->data,value) == 0 && currNode == head) {
                LinkedList_pop_front();
                currNode = head;
            }
            else if (strcmp(currNode->data, value) == 0) {
                Node* nextNode = currNode->next;
                Node* previousNode = currNode->previous;
                free(currNode->data);
                free(currNode);
                previousNode->next = nextNode;
                nextNode->previous = previousNode;
            }
            else {
                currNode = currNode->next;
            }
        }
        if (strcmp(head->data, value) == 0) {
            free(head->data);
            free(head);
            head = NULL;
        }
    }
}

void LinkedList_reverse(void) {

    if (head == NULL) {
        printf("Error! Empty Linked List!");
        return;
    }
    Node* currNode = head;
    while (currNode != NULL) {
        Node* temp = currNode->next;
        currNode->next = currNode->previous;
        currNode->previous = temp;

        currNode = temp;
    }
    Node* temp = tail;
    tail = head;
    head = temp;
}

size_t LinkedList_size(void) {
    Node* currNode = head;
    size_t count = 0;
    while (currNode != NULL) {
        count++;
        currNode = currNode->next;
    }
    return count;
}

void LinkedList_output_list(void) {
    if (head != NULL) {
        Node* currNode = head;
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

char* LinkedList_toString(void);