#include <stdio.h>
#include <string.h>

struct Book{
	int bookId;
	char title[50];
	char author[50];
	float price;
	char category[50];
};

void addBooks(Book books[], int *size){
	printf("Moi ban nhap so luong sach: ");
	scanf("%d", &*size);
	printf("Moi ban nhap thong tin sach\n");
	for(int i=0; i<*size; i++){
		printf("Ma sach: ");
		fflush(stdin);
		scanf("%d", &books[i].bookId);
		printf("Ten sach: ");
		fflush(stdin);
		fgets(books[i].title,50,stdin);
		printf("Tac gia: ");
		fflush(stdin);
		fgets(books[i].author,50,stdin);
		printf("Gia sach: ");
		fflush(stdin);
		scanf("%0.f", &books[i].price);
		printf("The loai: ");
		fflush(stdin);
		fgets(books[i].category,50,stdin);
	}
}

void saveBookinfo(Book books[], int *size){
	FILE *file;
	file=fopen("book_nhi_phan.bin","wb");
	if (file == NULL) {
        printf("Khong the mo file");
        return;
    }
	for (int i = 0; i <*size; i++) {
    	fwrite(&books[i], sizeof(Book), 1, file);
		}
    fclose(file);
}
void getInfor(Book books[], int *size){
	FILE *file;
	file = fopen("Book_nhi_phan.bin", "rb");
    if (file == NULL) {
        printf("Khong the mo file");
        return;
    }
    for (int i = 0; i <*size; i++) {
    	fread(&books[i], sizeof(Book), 1, file);
		}
    fclose(file);
    printf("Lay thong tin sach tu file thanh cong");
}

void showBooks(Book books[], int *size) {
    if (*size == 0) {
        printf("Danh sach sach trong");
        return;
    }
    printf("\nDanh sach cac cuon sach:\n");
    for (int i = 0; i < *size; i++) {
        printf("\nThong tin sach thu %d:\n", i + 1);
        printf("Ma sach: %s\n", books[i].bookId);
        printf("Ten sach: %s\n", books[i].title);
        printf("Tac gia: %s\n", books[i].author);
        printf("Gia tien: %.2f\n", books[i].price);
        printf("The loai: %s\n", books[i].category);
    }
}

int main(){
	FILE *file;
	struct Book books[100];
	int choice;
	int size;
	do{
		printf("1.Nhap so luong va thong tin sach\n");
		printf("2.Luu thong tin sach vao file\n");
		printf("3.Lay thong tin sach tu file\n");
		printf("4.Hien thi thong tin sach\n");
		printf("5.Thoat chuong trinh\n");
		printf("Lua chon cua ban: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				addBooks(books, &size);
				break;
			case 2:
				saveBookinfo(books, &size);
				break;
			case 3:
				getInfor(books, &size);
				break;
			case 4:
				showBooks(books, &size);
				break;
			case 5:
				printf("Thoat chuong trinh!!");
				break;
			default:
				printf("Lua chon khong hop le!!!");
				break;
		}
	}while(choice!=5);
	return 0;
}
