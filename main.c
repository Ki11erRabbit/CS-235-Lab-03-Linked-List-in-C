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

                    LinkedList_push_front(strdup(token));
                    printf("%s ", token);
                    token = strtok(NULL, " ");
                }
                printf("\n");
            }
            else if (strcmp(token,"PrintList") == 0) {//PrintList
                printf ("PrintList ");
                LinkedList_output_list();

            }
            else if (strcmp(token,"Clear") == 0) {//Clear
                printf("Clear ");//TODO: change to match error cases
                LinkedList_clear();
                printf("\n");
            }
            else if (strcmp(token,"Size") == 0) {//Size
                printf("Size %d\n", LinkedList_size());
            }
            else if (strcmp(token,"Empty") == 0) {//Empty
                printf("Empty ");
                if (LinkedList_is_empty()) {
                    printf("true\n");
                }
                else {
                    printf("false\n");
                }
            }
            else if (strcmp(token,"First") == 0) {//First
                printf("First ");
                printf("%s\n",LinkedList_front());
            }
            else if (strcmp(token,"Delete") == 0) {//Delete
                printf("Delete ");
                LinkedList_pop_front();
                printf("\n");
            }
            else if (strcmp(token,"Remove") == 0) {//Remove
                printf("Remove ");
                token = strtok(NULL, " ");
                token = strtok(token, "\n");
                printf("%s\n",token);
                LinkedList_remove_value(token);
            }
            else if (strcmp(token,"Reverse") == 0) {
                printf("Reverse OK\n");
                LinkedList_reverse();
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

    LinkedList_clear();



    return fclose(readFile);// + fclose(writeFile);
}

