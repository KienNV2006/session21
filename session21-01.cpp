#include<stdio.h>
int main(){
	FILE *fptr;
	fptr = fopen("bt01.txt", "w");
	if (fptr == NULL) {
        printf("Khong the mo file");
        return 1;
    }
	fprintf(fptr, "Hello World");
	fclose(fptr);
}