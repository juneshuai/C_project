#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _studentList {
	char name[10]; //이름
	int id; //학번
	char major[20]; //학과
	char grade[6]; // 학점
	float score; //평점
	struct _studentList* next;
}studentList;

void init();
void readList();
void addStudent();
void updateStudent();
void seaching_Student_Date();

int main(void) {

	init();
	int num;


	while (1) {
		printf("\n================\n");
		printf("1. 읽기\n");
		printf("2. 추가\n");
		printf("3. 갱신\n");
		printf("4. 삭제\n");
		printf("5. 검색\n");
		printf("6. 저장\n");
		printf("7. 종료\n");
		printf("================\n");
		printf("\n원하는 메뉴의 번호를 입력하세요:");
		scanf_s("%d", &num);
		switch (num)
		{
		case 1:
			readList();
			break;
		case 2:
			addStudent();
			break;
		case 3:
			updateStudent();
			break;

		case 5:
			seaching_Student_Date();
			break;
		default:
			exit(0);
			break;
		}
		/*init();*/
	}

	return 0;

}

//0. 초기화 연결리스트 성공
void init() {


	FILE* fp = NULL;
	errno_t err;
	err = fopen_s(&fp, "studentlist.txt", "r");

	if (err == 0) {
		printf("\n파일 열기 성공\n");
	}
	else {
		printf("\n파일 열기 실패\n");
	}

	studentList* head, * tail;
	studentList* ptr;

	head = tail = NULL;
	studentList* dummy = (studentList*)malloc(sizeof(studentList));
	head = dummy;
	tail = dummy;
	while (!feof(fp)) {
		ptr = (studentList*)malloc(sizeof(studentList));
		if (ptr == NULL)
		{
			printf("메모리 할당오류! \n");
			exit(1);
		}

		fscanf_s(fp, "%s %d", ptr->name, sizeof(ptr->name), &ptr->id, sizeof(ptr->id));
		//printf("%s %d ", ptr->name, ptr->id);

		fscanf_s(fp, "%s %s", ptr->major, sizeof(ptr->major), ptr->grade, sizeof(ptr->grade)); //저도 왜이렇게 써야하는지 모르겠는데 fscanf_s가 2개만 인자를 받네요;;
		//printf("%s %s ", ptr->major, ptr->grade);

		fscanf_s(fp, "%f", &ptr->score, sizeof(ptr->score));
		//printf("%0.1f", ptr->score);

		//printf("\n\n");

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
	FILE* fp = NULL;
	errno_t err;
	err = fopen_s(&fp, "studentlist.txt", "r");

	if (err == 0) {
		printf("\n파일 열기 성공\n");
	}
	else {
		printf("\n파일 열기 실패\n");
	}
	printf("\n==========================================\n");
	printf("이름\t학번\t학과\t학점\t평점\n");
	printf("==========================================\n");
	while (!feof(fp)) {
		fgets(str, 100, fp);
		printf("%s", str);
		cnt++;
	}
	printf("\n");
	printf("==========================================\n");
	printf("라인 갯수 : %d\n", cnt);


	fclose(fp);

}

//2. 추가
void addStudent() {

	FILE* fp = NULL;
	errno_t err;
	char str[100];
	char temp_text[100];
	err = fopen_s(&fp, "studentlist.txt", "a");

	if (err == 0) {
		printf("\n파일 열기 성공\n");
	}
	else {
		printf("\n파일 열기 실패\n");
	}

	printf("\n추가할 학생 정보(이름 학번 학과 학점 평점)를 입력하세요 :");

	gets(temp_text);
	/*scanf가 선행돼서 get_s가 씹히네요. 일단 지우기용 gets쓰고 아래에 gets_s 써서
	해결은 했습니다만, 더 좋은 방법 아시는 분 있으면 알려주세요!
	*/
	gets_s(temp_text, 100);

	printf("%s", temp_text);

	fputs("\n", fp); // 줄바꿈 삽입용

	fputs(temp_text, fp); // 내용 삽입

	fclose(fp);

	readList();



}
void seaching_Student_Date() {

	FILE* fp = NULL;
	errno_t err;
	err = fopen_s(&fp, "studentlist.txt", "r");

	if (err == 0) {
		printf("\n파일 열기 성공\n");
	}
	else {
		printf("\n파일 열기 실패\n");
	}

	studentList* head, * tail;
	studentList* ptr;

	head = tail = NULL;
	studentList* dummy = (studentList*)malloc(sizeof(studentList));
	head = dummy;
	tail = dummy;

	while (!feof(fp)) {
		ptr = (studentList*)malloc(sizeof(studentList));
		if (ptr == NULL)
		{
			printf("메모리 할당오류! \n");
			exit(1);
		}

		fscanf_s(fp, "%s %d", ptr->name, sizeof(ptr->name), &ptr->id, sizeof(ptr->id));
		fscanf_s(fp, "%s %s", ptr->major, sizeof(ptr->major), ptr->grade, sizeof(ptr->grade));
		fscanf_s(fp, "%f", &ptr->score, sizeof(ptr->score));

		tail->next = ptr;

		ptr->next = NULL;
		tail = ptr;



	}
	ptr = head->next;
	char stName[100];
	int find_pos;
	char * p;
	int searched_Student=0;


	printf("검색하고 싶은 학생 이름은?");

	scanf_s("%s", stName, sizeof(stName));

	printf("\n==========================================\n");
	printf("이름\t학번\t학과\t학점\t평점\n");
	printf("==========================================\n");

	while (ptr) {
		if (strcmp(ptr->name, stName) == 0) {
	
			
			if (searched_Student == 0) {

			
			}
			searched_Student++;
			printf("%s %d %s %s %.1f\n", ptr->name, ptr->id, ptr->major, ptr->grade, ptr->score);
			
	
	

		}
		ptr = ptr->next;
		if (ptr == NULL) {
			if (searched_Student == 0) {
				printf("==========================================\n");
				printf("%s(이)라는 학생은 없습니다.\n", stName);
			}
			else {
				printf("==========================================\n");
				printf("총 %d명의 학생을 찾았습니다.\n\n", searched_Student);
			}
			break;
		}
	}
	fclose(fp);
}

void updateStudent() {

	FILE* fp = NULL;
	errno_t err;

	err = fopen_s(&fp, "studentlist.txt", "r+t"); // 이 모드로 해야지 읽고 수정 가능

	if (err == 0) {
		printf("\n파일 열기 성공\n");
	}
	else {
		printf("\n파일 열기 실패\n");
	}

	studentList* head, * tail;
	studentList* ptr;

	head = tail = NULL;
	studentList* dummy = (studentList*)malloc(sizeof(studentList));
	head = dummy;
	tail = dummy;
	while (!feof(fp)) {
		ptr = (studentList*)malloc(sizeof(studentList));
		if (ptr == NULL)
		{
			printf("메모리 할당오류! \n");
			exit(1);
		}

		fscanf_s(fp, "%s %d", ptr->name, sizeof(ptr->name), &ptr->id, sizeof(ptr->id));
		//printf("%s %d ", ptr->name, ptr->id);

		fscanf_s(fp, "%s %s", ptr->major, sizeof(ptr->major), ptr->grade, sizeof(ptr->grade)); //저도 왜이렇게 써야하는지 모르겠는데 fscanf_s가 2개만 인자를 받네요;;
		//printf("%s %s ", ptr->major, ptr->grade);

		fscanf_s(fp, "%f", &ptr->score, sizeof(ptr->score));
		//printf("%0.1f", ptr->score);

		//printf("\n\n");

		tail->next = ptr;

		ptr->next = NULL;
		tail = ptr;



	}
	rewind(fp);
	ptr = head->next;
	int size;
	size = ftell(fp);
	printf("현재 커서 위치 : %d\n", size);
	char stName[10];
	char temp[256];
	int find_pos;
	int change_num;
	char change_major[20];
	char change_grade[5];
	float change_score;
	printf("갱신하고 싶은 학생 이름은?");
	
	scanf_s("%s", stName, sizeof(stName));
	if (err == 0) 
	{
		while (ptr)
		{
			while (fgets(temp, 256, fp) != NULL) //temp에 값잘들어가요
			{
				printf("\n강호동 전에 : %d\n",ftell(fp));
				printf("strlen확인 : %d",  strlen(temp));
			
				if (strcmp(ptr->name, stName) == 0) 
				{

					find_pos = strlen(temp) - 6;
					fseek(fp, (-1) * find_pos, SEEK_CUR); // 이름 앞까지 커서 옮겨서 수정해버리려고 사용했어요
					printf("리스트에서 data \"%s\"을 찾았습니다.\n", stName);
					printf("\n==========================================\n");
					printf("이름\t학번\t학과\t학점\t평점\n");
					printf("==========================================\n");
					printf("%s %d %s %s %.1f\n", ptr->name, ptr->id, ptr->major, ptr->grade, ptr->score);
					size = ftell(fp);
					printf("현재 위치 : %d\n\n", size);
					printf("%s 학생의 새로운 정보 (학번 학과 학점 평점)를 입력하세요 :", stName);
					
					
					
					scanf_s("%d %s %s %f", &change_num, change_major, sizeof(change_major), change_grade, sizeof(change_grade), &change_score); // 여기서 왜 자동으로 쓰레기값이 들어가는 지 알고 싶네요;;
					
					fprintf(fp,"%d %s %s %.1f",change_num, change_major, change_grade, change_score);
					fflush(fp);

					fseek(fp, 0, SEEK_END);


					break;

				}
				ptr = ptr->next;
				
				if (ptr == NULL) 
				{
					printf("데이터 \"%s\"이(가) 리스트에 존재하지 않습니다.\n", stName);
					break;
				}
				
			}
			
			break;
		}
	
	}



	fclose(fp);


}