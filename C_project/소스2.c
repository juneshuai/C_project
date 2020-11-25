#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _studentList {
	char name[10]; //�̸�
	int id; //�й�
	char major[20]; //�а�
	char grade[4]; // ����
	int score; //����
	struct _studentList *next;
}studentList;

void init();
void readList();

int main(void) {
	
	init();
	/*int num;
	
	
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
	
	return 0;*/
	
}

//0. �ʱ�ȭ
void init() {
	FILE *fp = NULL;
	errno_t err;
	err = fopen_s(&fp, "studentlist.txt", "r");

	if (err == 0) {
		printf("���� ���� ����\n");
	}
	else {
		printf("���� ���� ����\n");
	}

	studentList *head, *tail;
	studentList *ptr;

	head = tail = NULL;
	studentList *dummy = (studentList *)malloc(sizeof(studentList));
	head = dummy;
	tail = dummy;
	while (1) {
		ptr = (studentList *)malloc(sizeof(studentList));
		if (ptr == NULL)
		{
			printf("�޸� �Ҵ����! \n");
			exit(1);
		}
		fscanf_s("%s", ptr->name);
		printf("%s", ptr->name);
		break;
	}
	fclose(fp);

}



//1. �б�(���Ḯ��Ʈ �ʱ�ȭ)
void readList() {
	int cnt = 0; //���� ��������
	char str[100];
	FILE *fp = NULL;
	errno_t err;
	err = fopen_s(&fp, "studentlist.txt", "r");

	if (err == 0) {
		printf("���� ���� ����\n");
	}
	else {
		printf("���� ���� ����\n");
	}
	
	while(!feof(fp)){
		fgets(str, 100, fp);
		printf("%s", str);
		cnt++;
	}
	printf("\n");
	printf("���� ���� : %d\n", cnt);
	
	
	fclose(fp);
	
}

//2. �߰�
void addStudent() {
	FILE *fp = NULL;
	errno_t err;
	err = fopen_s(&fp, "studentlist.txt", "a");
	if (err == 0) {
		printf("���� ���� ����\n");
	}
	else {
		printf("���� ���� ����\n");
	}

	
}


