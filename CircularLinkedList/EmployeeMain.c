#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.c"
#include "Employee.h"

Employee * WhosNightDuty(List * plist, char * name, int days);

int main(void)
{
	// 원형 연결 리스트의 생성 및 초기화
	List list;
	Employee *pemp;
	int i;
	ListInit(&list);

	// 리스트에 5개의 데이터를 저장
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

	//할당된 메모리 전체 소멸
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
			//찾는 이름과 List의 이름이 같으면
			if(strcmp(pemp->name, name) == 0)
				break;
		}
		//이름이 존재하지 않는 경우
		if(i >= LCount(plist)-1){
			return NULL;
		}
	}

	//days뒤의 사람 찾기
	for(i=0; i<days; i++){
		LNext(plist, &pemp);
	}

	return pemp;
		
}