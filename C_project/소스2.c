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
		printf("1. �б�\n");
		printf("================\n");
		printf("���ϴ� �޴��� ��ȣ�� �Է��ϼ���:");
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


//1. �б�
void readList() {
	char str[100];
	FILE *fp = NULL;
	errno_t err;
	err = fopen_s(&fp, "studentlist.txt", "r");

	if (err == 0) {
		printf("����\n");
	}
	else {
		printf("����\n");
	}
	
	while(!feof(fp)){
		fgets(str, 100, fp);
		printf("%s", str);
	}

	printf("\n");
	fclose(fp);
	
}
//, , s1->grade, sizeof(s1->grade), s1->score, sizeof(s1->score)


