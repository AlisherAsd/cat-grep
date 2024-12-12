#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int readFile(char *flag, char *searchString, char *filename) {
    FILE *filePointer;

    filePointer = fopen(filename, "r");


    if (filePointer == NULL) {
        printf("Ошибка при открытии файла для чтения!\n");
        return 1;
    }

    if (flag == NULL) {
        char buffer[100];
        while (fgets(buffer, sizeof(buffer), filePointer)) {
            if (strstr(buffer, searchString) != 0) {
                printf("%s", buffer);
            }
        }
        fclose(filePointer);
        return 0;
    }

    fclose(filePointer);
    return 1;
}



int main(int argc, char *argv[]) {

    if (strcmp("mgrep", argv[1]) != 0) {
        printf("Команда %s не существует!\n", argv[1]);
        return 1; 
    }

    if (argv[4] == NULL) {
        readFile(NULL, argv[2], argv[3]);
        return 0;
    }
    if (argv[4] != NULL) {
        readFile(argv[2], argv[3], argv[4]);
        return 0;
    }

    return 1; 
}