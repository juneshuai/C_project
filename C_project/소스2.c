#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _studentList {
	char name[10];
	int id;
	char major[20];
	char grade[4];
	int score;
}studentList;


void readList();

int main(void) {
	int num;
	while(1){
		printf("================\n");
		printf("1. 읽기\n");
		printf("================\n");
		printf("원하는 메뉴의 번호를 입력하세요:");
		scanf_s("%d", &num);
		switch (num)
		{
			case 1:
				readList();
				break;
		default:
			break;
		}
	}
	
	return 0;
	
}


//1. 읽기
void readList() {
	char str[100];
	FILE *fp = NULL;
	errno_t err;
	err = fopen_s(&fp, "studentlist.txt", "r");

	if (err == 0) {
		printf("성공\n");
	}
	else {
		printf("실패\n");
	}
	
	while(!feof(fp)){
		fgets(str, 100, fp);
		printf("%s", str);
	}

	printf("\n");
	fclose(fp);
	
}
//, , s1->grade, sizeof(s1->grade), s1->score, sizeof(s1->score)


