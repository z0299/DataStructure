#include <stdio.h>
#include <string.h>
#include "NameCard.h"

//NameCard ����ü ������ ���� �Ҵ� �� �ʱ�ȭ �� �ּ� �� ��ȯ
NameCard * MakeNameCard(char * name, char * phone){
    NameCard * card;
    card = (NameCard*)malloc(sizeof(NameCard));
    strcpy(card->name, name);
    strcpy(card->phone, phone);
    return card;
}

//NameCard ����ü ������ ���� ���
void ShowNameCardInfo(NameCard * pcard){
    printf("�̸�: %s\n", pcard->name);
    printf("��ȭ��ȣ: %s\n", pcard->phone);

    return 0;
}

//�̸��� ������ 0, �ٸ��� 0�� �ƴ� �� ��ȯ
int NameCompare(NameCard * pcard, char * name){
    return strcmp(pcard->name, name);
    // if(pcard->name == name)
    //     return 0;
    // else
    //     return 1;
}

//��ȭ��ȣ ������ ����
void ChangePhoneNum(NameCard * pcard, char * phone){
    strcpy(pcard->phone, phone);

    return 0;
}