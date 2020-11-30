#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _studentList {
	char name[10]; //�̸�
	int id; //�й�
	char major[20]; //�а�
	char grade[6]; // ����
	float score; //����
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
		printf("1. �б�\n");
		printf("2. �߰�\n");
		printf("3. ����\n");
		printf("4. ����\n");
		printf("5. �˻�\n");
		printf("6. ����\n");
		printf("7. ����\n");
		printf("================\n");
		printf("\n���ϴ� �޴��� ��ȣ�� �Է��ϼ���:");
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

//0. �ʱ�ȭ ���Ḯ��Ʈ ����
void init() {


	FILE* fp = NULL;
	errno_t err;
	err = fopen_s(&fp, "studentlist.txt", "r");

	if (err == 0) {
		printf("\n���� ���� ����\n");
	}
	else {
		printf("\n���� ���� ����\n");
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
			printf("�޸� �Ҵ����! \n");
			exit(1);
		}

		fscanf_s(fp, "%s %d", ptr->name, sizeof(ptr->name), &ptr->id, sizeof(ptr->id));
		//printf("%s %d ", ptr->name, ptr->id);

		fscanf_s(fp, "%s %s", ptr->major, sizeof(ptr->major), ptr->grade, sizeof(ptr->grade)); //���� ���̷��� ����ϴ��� �𸣰ڴµ� fscanf_s�� 2���� ���ڸ� �޳׿�;;
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

//1. �б�(���Ḯ��Ʈ �ʱ�ȭ)
void readList() {
	int cnt = 0; //���� ��������
	char str[100];
	FILE* fp = NULL;
	errno_t err;
	err = fopen_s(&fp, "studentlist.txt", "r");

	if (err == 0) {
		printf("\n���� ���� ����\n");
	}
	else {
		printf("\n���� ���� ����\n");
	}
	printf("\n==========================================\n");
	printf("�̸�\t�й�\t�а�\t����\t����\n");
	printf("==========================================\n");
	while (!feof(fp)) {
		fgets(str, 100, fp);
		printf("%s", str);
		cnt++;
	}
	printf("\n");
	printf("==========================================\n");
	printf("���� ���� : %d\n", cnt);


	fclose(fp);

}

//2. �߰�
void addStudent() {

	FILE* fp = NULL;
	errno_t err;
	char str[100];
	char temp_text[100];
	err = fopen_s(&fp, "studentlist.txt", "a");

	if (err == 0) {
		printf("\n���� ���� ����\n");
	}
	else {
		printf("\n���� ���� ����\n");
	}

	printf("\n�߰��� �л� ����(�̸� �й� �а� ���� ����)�� �Է��ϼ��� :");

	gets(temp_text);
	/*scanf�� ����ż� get_s�� �����׿�. �ϴ� ������ gets���� �Ʒ��� gets_s �Ἥ
	�ذ��� �߽��ϴٸ�, �� ���� ��� �ƽô� �� ������ �˷��ּ���!
	*/
	gets_s(temp_text, 100);

	printf("%s", temp_text);

	fputs("\n", fp); // �ٹٲ� ���Կ�

	fputs(temp_text, fp); // ���� ����

	fclose(fp);

	readList();



}
void seaching_Student_Date() {

	FILE* fp = NULL;
	errno_t err;
	err = fopen_s(&fp, "studentlist.txt", "r");

	if (err == 0) {
		printf("\n���� ���� ����\n");
	}
	else {
		printf("\n���� ���� ����\n");
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
			printf("�޸� �Ҵ����! \n");
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


	printf("�˻��ϰ� ���� �л� �̸���?");

	scanf_s("%s", stName, sizeof(stName));

	printf("\n==========================================\n");
	printf("�̸�\t�й�\t�а�\t����\t����\n");
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
				printf("%s(��)��� �л��� �����ϴ�.\n", stName);
			}
			else {
				printf("==========================================\n");
				printf("�� %d���� �л��� ã�ҽ��ϴ�.\n\n", searched_Student);
			}
			break;
		}
	}
	fclose(fp);
}

void updateStudent() {

	FILE* fp = NULL;
	errno_t err;

	err = fopen_s(&fp, "studentlist.txt", "r+t"); // �� ���� �ؾ��� �а� ���� ����

	if (err == 0) {
		printf("\n���� ���� ����\n");
	}
	else {
		printf("\n���� ���� ����\n");
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
			printf("�޸� �Ҵ����! \n");
			exit(1);
		}

		fscanf_s(fp, "%s %d", ptr->name, sizeof(ptr->name), &ptr->id, sizeof(ptr->id));
		//printf("%s %d ", ptr->name, ptr->id);

		fscanf_s(fp, "%s %s", ptr->major, sizeof(ptr->major), ptr->grade, sizeof(ptr->grade)); //���� ���̷��� ����ϴ��� �𸣰ڴµ� fscanf_s�� 2���� ���ڸ� �޳׿�;;
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
	printf("���� Ŀ�� ��ġ : %d\n", size);
	char stName[10];
	char temp[256];
	int find_pos;
	int change_num;
	char change_major[20];
	char change_grade[5];
	float change_score;
	printf("�����ϰ� ���� �л� �̸���?");
	
	scanf_s("%s", stName, sizeof(stName));
	if (err == 0) 
	{
		while (ptr)
		{
			while (fgets(temp, 256, fp) != NULL) //temp�� ���ߵ���
			{
				printf("\n��ȣ�� ���� : %d\n",ftell(fp));
				printf("strlenȮ�� : %d",  strlen(temp));
			
				if (strcmp(ptr->name, stName) == 0) 
				{

					find_pos = strlen(temp) - 6;
					fseek(fp, (-1) * find_pos, SEEK_CUR); // �̸� �ձ��� Ŀ�� �Űܼ� �����ع������� ����߾��
					printf("����Ʈ���� data \"%s\"�� ã�ҽ��ϴ�.\n", stName);
					printf("\n==========================================\n");
					printf("�̸�\t�й�\t�а�\t����\t����\n");
					printf("==========================================\n");
					printf("%s %d %s %s %.1f\n", ptr->name, ptr->id, ptr->major, ptr->grade, ptr->score);
					size = ftell(fp);
					printf("���� ��ġ : %d\n\n", size);
					printf("%s �л��� ���ο� ���� (�й� �а� ���� ����)�� �Է��ϼ��� :", stName);
					
					
					
					scanf_s("%d %s %s %f", &change_num, change_major, sizeof(change_major), change_grade, sizeof(change_grade), &change_score); // ���⼭ �� �ڵ����� �����Ⱚ�� ���� �� �˰� �ͳ׿�;;
					
					fprintf(fp,"%d %s %s %.1f",change_num, change_major, change_grade, change_score);
					fflush(fp);

					fseek(fp, 0, SEEK_END);


					break;

				}
				ptr = ptr->next;
				
				if (ptr == NULL) 
				{
					printf("������ \"%s\"��(��) ����Ʈ�� �������� �ʽ��ϴ�.\n", stName);
					break;
				}
				
			}
			
			break;
		}
	
	}



	fclose(fp);


}