#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.c"
#include "Employee.h"

Employee * WhosNightDuty(List * plist, char * name, int days);

int main(void)
{
	// ���� ���� ����Ʈ�� ���� �� �ʱ�ȭ
	List list;
	Employee *pemp;
	int i;
	ListInit(&list);

	// ����Ʈ�� 5���� �����͸� ����
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 11111;
	strcpy(pemp->name, "Terry");
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 22222;
	strcpy(pemp->name, "Jery");
	LInsert(&list, pemp);
	
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 33333;
	strcpy(pemp->name, "Hary");
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 44444;
	strcpy(pemp->name, "Sunny");
	LInsert(&list, pemp);

	pemp = WhosNightDuty(&list, "Sunny", 3);
	printf("Employee name: %s\n", pemp->name);
	printf("Employee num: %d\n", pemp->empNum);

	//�Ҵ�� �޸� ��ü �Ҹ�
	if(LFirst(&list, &pemp)){
		free(pemp);

		for(i=0; i<LCount(&list)-1; i++){
			LNext(&list, &pemp);
			free(pemp);
		}
	}
}

Employee * WhosNightDuty(List * plist, char * name, int days){
	Employee * pemp;
	int i;

	LFirst(plist, &pemp);
	if(strcmp(pemp->name, name) != 0){
		for(i = 0; i<LCount(plist)-1; i++){
			LNext(plist, &pemp);
			//ã�� �̸��� List�� �̸��� ������
			if(strcmp(pemp->name, name) == 0)
				break;
		}
		//�̸��� �������� �ʴ� ���
		if(i >= LCount(plist)-1){
			return NULL;
		}
	}

	//days���� ��� ã��
	for(i=0; i<days; i++){
		LNext(plist, &pemp);
	}

	return pemp;
		
}