#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int readFile(char *name, char *flag) {
    FILE *filePointer;

    filePointer = fopen(name, "r");

    if (filePointer == NULL) {
        printf("Ошибка при открытии файла для чтения!\n");
        return 1;
    }

    if (flag == NULL) {
        char buffer[100];
        while (fgets(buffer, sizeof(buffer), filePointer)) {
            printf("%s", buffer);
        }
        fclose(filePointer);
        return 0;
    }

    if (strcmp("-n", flag) == 0) {
        char buffer[100];
        int count = 1;
        while (fgets(buffer, sizeof(buffer), filePointer)) {
            printf("%s%d%s%s",  "     ", count, "  ", buffer);
            count++;
        }
        fclose(filePointer);
        count = 0;
        return 0;
    }

    fclose(filePointer);
    return 1;
}



int main(int argc, char *argv[]) {

    if (strcmp("mcat", argv[1]) != 0) {
        printf("Команда %s не существует!\n", argv[1]);
        return 1; 
    }
    if (argv[3] == NULL) {
        readFile(argv[2], NULL);
        return 0;
    }
    if (argv[3] != NULL) {
        readFile(argv[3], argv[2]);
        return 0;
    }

    return 1; 
}