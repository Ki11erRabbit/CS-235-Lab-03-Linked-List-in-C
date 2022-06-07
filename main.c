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
    size_t buffSize = 100;
    while (getline(&buff, &buffSize, readFile)) {
        buff = strtok(buff, "\n");//trims newline character

        //printf("BUFFFER: %s\n", buff);
        if (buff != NULL) {
            char* token = strtok(buff, " ");
            //char* command = strdup(token);

            if (token[0] == 'I') {
                printf("Insert ");
                token = strtok(NULL, " ");

                while (token != NULL) {

                    LinkedList_push_front(strdup(token));
                    printf("%s ", token);
                    token = strtok(NULL, " ");
                }
                printf("\n");
            }
            else if (token[0] == 'P') {
                printf ("PrintList ");
                LinkedList_output_list();

            }
            else if (token[0] == 'C') {
                printf("Clear ");//TODO: change to match error cases
                LinkedList_clear();
                printf("\n");
            }

        }
        else {
            break;
        }

    }
    free(buff);
    LinkedList_clear();



    return fclose(readFile);// + fclose(writeFile);
}

