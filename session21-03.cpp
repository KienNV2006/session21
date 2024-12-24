#include<stdio.h>
int main(){
	FILE *fptr;
	char myString[100];
	fptr = fopen("bt01.txt", "a");
	if (fptr == NULL) {
        printf("Khong the mo file");
        return 1;
    }else{
	printf("Moi ban nhap vao mot chuoi can chen: ");
	fgets(myString, 100, stdin);
	fprintf(fptr, "%s", myString);
	fclose(fptr);
	}
	return 0;	
}