#include<stdio.h>
int main() {
    FILE *fptr;
    char myString[100];
    fptr = fopen("bt01.txt","r");
    if (fptr == NULL) {
        printf("Khong the mo file");
        return 1;
    }else{
    fgets(myString, sizeof(myString), fptr);
    printf("Dong dau tien trog file la: %s\n", myString);
    fclose(fptr);
	}
    return 0;
}
