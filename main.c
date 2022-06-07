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
    size_t* buffSize = 0;
    while (getline(&buff, &buffSize, readFile)) {
        buff = strtok(buff, "\n");//trims newline character
        //printf("%d", buffSize);
        //printf("BUFFFER: %s\n", buff);
        if (buff != NULL) {
            char* token = strtok(buff, " ");
            //char* command = strdup(token);

            if (token[0] == 'I') {//Insert
                printf("Insert ");
                token = strtok(NULL, " ");

                while (token != NULL) {

                    LinkedList_push_front(strdup(token));
                    printf("%s ", token);
                    token = strtok(NULL, " ");
                }
                printf("\n");
            }
            else if (token[0] == 'P') {//PrintList
                printf ("PrintList ");
                LinkedList_output_list();

            }
            else if (token[0] == 'C') {//Clear
                printf("Clear ");//TODO: change to match error cases
                LinkedList_clear();
                printf("\n");
            }
            else if (token[0] == 'S') {//Size
                printf("Size %d\n", LinkedList_size());
            }
            else if (token[0] == 'E') {//Empty
                printf("Empty ");
                if (LinkedList_is_empty()) {
                    printf("true\n");
                }
                else {
                    printf("false\n");
                }
            }
            else if (token[0] == 'F') {//First
                printf("First ");
                printf("%s\n",LinkedList_front());
            }
            else if (token[0] == 'D') {//Delete
                printf("Delete ");
                LinkedList_pop_front();
                printf("\n");
            }
            else if (token[0] == 'R') {//Remove
                printf("Remove ");
                token = strtok(NULL, " ");
                token = strtok(token, "\n");
                printf("%s\n",token);
                LinkedList_remove_value(token);
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

