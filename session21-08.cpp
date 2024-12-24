#include <stdio.h>
#include <string.h>

struct SinhVien{
	int id;
	char name[50];
	int age;
};

int main(){
	struct SinhVien sv[100];
	int count=0;
	FILE *fptr;
	fptr=fopen("students.txt","r");
	if(fptr==NULL){
		printf("Khong the mo file students.txt\n");
		return 1;
	}
	while (count<100 && fscanf(fptr, "%d,%49[^,],%d", &sv[count].id, sv[count].name, &sv[count].age)==3) {
    count++;
	}
	fclose(fptr);
	printf("Danh sach sinh vien\n");
	for(int i=0; i<count; i++){
		printf("ID: %d\n Ten: %s\n Tuoi: %d\n", sv[i].id, sv[i].name, sv[i].age);
	}
	return 0;
}