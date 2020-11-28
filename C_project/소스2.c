#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _studentList {
	char name[10]; //�̸�
	int id; //�й�
	char major[20]; //�а�
	char grade[4]; // ����
	float score; //����
	struct _studentList* next;
}studentList;

void init();
void readList();
void addStudent();

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
		default:
			exit(0);
			break;
		}
		init();
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


