#include <stdio.h>
int main() {
    FILE *fptr;
    int current;
    char myString[100];
    fptr = fopen("bt05.txt", "w");
    if (fptr == NULL) {
        printf("Khong the mo file\n");
        return 1;
    }
    printf("Moi ban nhap so dong: ");
    scanf("%d", &current);
    fflush(stdin);
    for (int i = 0;i < current;i++) {
        printf("Moi ban nhap noi dung dong thu %d: ", i + 1);
        fgets(myString, sizeof(myString), stdin);
        fprintf(fptr, "%s", myString);
    }
    fclose(fptr);
    fptr = fopen("bt05.txt", "r");
    if (fptr == NULL) {
        printf("Khong the mo file\n");
        return 1;
    }
    printf("\nNoi dung trong file bt05.txt:\n");
    while (fgets(myString, sizeof(myString), fptr) != NULL) {
        printf("%s", myString);
    }
    fclose(fptr);
    return 0;
}
