#include<stdio.h>
int main(){
	FILE *fptr;
	char firstChar;
	fptr = fopen("bt01.txt", "r");
	if (fptr == NULL) {
        printf("Khong the mo file");
        return 1;
    }
	firstChar = fgetc(fptr);
	printf("%c", firstChar);
	fclose(fptr);
	return 0;
}