#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main(int argc, char** argv) {

    FILE* readFile;
    //FILE* writeFile;
    if (argc < 2) {
        exit(1);
    }
    //printf("%s\n",argv[0]);
    //printf("%s\n",argv[1]);
    //printf("%s\n",argv[2]);
    readFile = fopen(argv[1],"r");
    //writeFile= fopen(argv[2],"w");



    char* buff = NULL;
    size_t buffSize = 0;
    Linked_List* list = LinkedList_Linked_List();
    Linked_List* list2 = NULL;
    while (getline(&buff, &buffSize, readFile)) {
        buff = strtok(buff, "\n");//trims newline character
        //printf("%d", buffSize);
        //printf("BUFFFER: %s\n", buff);
        if (buff != NULL) {
            char* token = strtok(buff, " ");
            //char* command = strdup(token);

            if (strcmp(token,"Insert") == 0) {//Insert
                printf("Insert ");
                token = strtok(NULL, " ");

                while (token != NULL) {
                    list->push_front(list,strdup(token));
                    //LinkedList_push_front(list,strdup(token));
                    printf("%s ", token);
                    token = strtok(NULL, " ");
                }
                printf("\n");
            }
            else if (strcmp(token,"PrintList") == 0) {//PrintList
                printf ("PrintList ");
                //LinkedList_output_list(list);
                list->print(list);

            }
            else if (strcmp(token,"Clear") == 0) {//Clear
                printf("Clear ");//TODO: change to match error cases
                //LinkedList_clear(list);
                list->clear(list);
                printf("\n");
            }
            else if (strcmp(token,"Size") == 0) {//Size
                printf("Size %d\n", list->size(list));
            }
            else if (strcmp(token,"Empty") == 0) {//Empty
                printf("Empty ");
                if (list->empty(list)) {
                    printf("true\n");
                }
                else {
                    printf("false\n");
                }
            }
            else if (strcmp(token,"First") == 0) {//First
                printf("First ");
                printf("%s\n",list->front(list));
            }
            else if (strcmp(token,"Delete") == 0) {//Delete
                printf("Delete ");
                //LinkedList_pop_front(list);
                list->pop_front(list);
                printf("\n");
            }
            else if (strcmp(token,"Remove") == 0) {//Remove
                printf("Remove ");
                token = strtok(NULL, " ");
                token = strtok(token, "\n");
                printf("%s\n",token);
                //LinkedList_remove_value(list,token);
                list->remove(list,token);
            }
            else if (strcmp(token,"Reverse") == 0) {
                printf("Reverse OK\n");
                //LinkedList_reverse(list);
                list->reverse(list);
            }
            else if (strcmp(token,"Append") == 0) {
                printf("Append ");
                token = strtok(NULL, " ");

                while (token != NULL) {
                    //LinkedList_push_back(list,strdup(token));
                    list->push_back(list,strdup(token));
                    printf("%s ", token);
                    token = strtok(NULL, " ");
                }
                printf("\n");
            }
            else if (strcmp(token, "Drop") == 0) {
                printf("Drop ");
                //LinkedList_pop_back(list);
                list->pop_back(list);
                printf("\n");
            }
            else if (strcmp(token, "Last") == 0) {
                printf("Last ");
                printf("%s\n", list->back(list));
            }
            else if (strcmp(token, "Copy") == 0) {
                printf("Copy ");
                //list2 = LinkedList_Copy(list);
                list2 = list->clone(list);
                printf("\n");
            }
            else if (strcmp(token, "PrintCopy") == 0) {
                printf("PrintList Copy ");
                //LinkedList_output_list(list2);
                list2->print(list2);
            }
            else {
                break;
            }

        }
        else {
            break;
        }
        free(buff);
        buff = NULL;
    }

    //LinkedList_Deconstruct(list);
    //LinkedList_Deconstruct(list2);
    list->deconstruct(list);
    list->deconstruct(list2);


    return fclose(readFile);// + fclose(writeFile);
}

