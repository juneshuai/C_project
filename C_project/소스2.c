#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _studentList {
	char name[10]; //이름
	int id; //학번
	char major[20]; //학과
	char grade[4]; // 학점
	float score; //평점
	struct _studentList *next;
}studentList;

void init();
void readList();

int main(void) {
	
	init();
	/*int num;
	
	
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
	
	return 0;*/
	
}

//0. 초기화 연결리스트 성공
void init() {
	FILE *fp = NULL;
	errno_t err;
	err = fopen_s(&fp, "studentlist.txt", "r");

	if (err == 0) {
		printf("파일 열기 성공\n");
	}
	else {
		printf("파일 열기 실패\n");
	}

	studentList *head, *tail;
	studentList *ptr;

	head = tail = NULL;
	studentList *dummy = (studentList *)malloc(sizeof(studentList));
	head = dummy;
	tail = dummy;
	while (!feof(fp)) {
		ptr = (studentList *)malloc(sizeof(studentList));
		if (ptr == NULL)
		{
			printf("메모리 할당오류! \n");
			exit(1);
		}
		fscanf_s(fp,"%s %d", ptr->name,sizeof(ptr->name), &ptr->id, sizeof(ptr->id));
		printf("%s %d ", ptr->name, ptr->id);
		fscanf_s(fp, "%s %s", ptr->major, sizeof(ptr->major), ptr->grade, sizeof(ptr->grade)); //저도 왜이렇게 써야하는지 모르겠는데 fscanf_s가 2개만 인자를 받네요;;
		printf("%s %s ", ptr->major, ptr->grade);
		fscanf_s(fp, "%f", &ptr->score, sizeof(ptr->score));
		printf("%0.1f", ptr->score);

		printf("\n\n");

		tail->next = ptr;

		ptr->next = NULL;
		tail = ptr;
		
	}
	fclose(fp);

}
//, ptr->major, ptr->grade, ptr->score
//, ptr->major,
//sizeof(ptr->major), ptr->grade, sizeof(ptr->grade), &ptr->score, sizeof(ptr->score)

//1. 읽기(연결리스트 초기화)
void readList() {
	int cnt = 0; //라인 갯수세기
	char str[100];
	FILE *fp = NULL;
	errno_t err;
	err = fopen_s(&fp, "studentlist.txt", "r");

	if (err == 0) {
		printf("파일 열기 성공\n");
	}
	else {
		printf("파일 열기 실패\n");
	}
	
	while(!feof(fp)){
		fgets(str, 100, fp);
		printf("%s", str);
		cnt++;
	}
	printf("\n");
	printf("라인 갯수 : %d\n", cnt);
	
	
	fclose(fp);
	
}

//2. 추가
void addStudent() {
	FILE *fp = NULL;
	errno_t err;
	err = fopen_s(&fp, "studentlist.txt", "a");
	if (err == 0) {
		printf("파일 열기 성공\n");
	}
	else {
		printf("파일 열기 실패\n");
	}

	
}


