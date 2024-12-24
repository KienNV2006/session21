#include <stdio.h>
int main() {
    FILE *sourceFile, *copyFile;
    char x;
    sourceFile = fopen("bt01.txt", "r");
    if (sourceFile == NULL) {
        printf("Khong the mo file\n");
        return 1;
    }
    copyFile = fopen("bt06.txt", "w");
    if (copyFile == NULL) {
        printf("Khong the mo file");
        return 1;
    }
    while ((x = fgetc(sourceFile)) != EOF) {
        fputc(x, copyFile);
    }
    fclose(sourceFile);
    fclose(copyFile);
    printf("Sao chep van ban bt01.txt sang bt06.txt thanh cong.\n");
    return 0;
}
