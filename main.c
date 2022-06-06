#include <stdio.h>
#include <stdlib.h>

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

    char buff[255];
    int numStudents, numGrades;
    fscanf(readFile, "%s", buff);
    numStudents = atoi(buff);
    fscanf(readFile, "%s", buff);
    numGrades = atoi(buff);
    //printf("%d %d \n", numStudents, numGrades);

    studentData studentList[numStudents];
    for (int i = 0; i < numStudents; i++) {
        studentList[i].grades = calloc(numGrades ,sizeof(int));
    }
    //printf("calloced\n");
    int numReads = 0;
    char* newBuff = NULL;
    size_t newBuffSize = 50;
    while (getline(&newBuff, &newBuffSize, readFile)) {
        //printf("Got line \n");
        if (newBuff[0] != '\n') {
            char* token = strtok(newBuff, " ");
            studentList[numReads].firstName = strdup(token);

            token = strtok(NULL, " ");
            studentList[numReads].lastName = strdup(token);

            //printf("%s %s\n",studentList[numReads].firstName, studentList[numReads].lastName);
            //printf("%s %s\n",studentList[0].firstName, studentList[0].lastName);

            token = strtok(NULL, " ");

            int count = 0;
            while (token != NULL) {
                studentList[numReads].grades[count] = atoi(token);
                //printf(" %d\n", studentList[numReads].grades[count]);
                token = strtok(NULL, " ");
                count++;
            }

            //printf("%s\n",newBuff);
            numReads++;
        }
        if (numReads == numStudents) break;
    }
    free(newBuff);



    return fclose(readFile);// + fclose(writeFile);
}

