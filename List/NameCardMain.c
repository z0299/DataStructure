#include <stdio.h>
#include <stdlib.h>
#include "NameCard.c"
#include "ArrayList.c"

int main(void){
    List list;
    NameCard * card;

    ListInit(&list);

    //1.�� 3���� ��ȭ��ȣ ������, �ռ� �츮�� ������ ����Ʈ�� �����Ѵ�.
    NameCard * card1 = MakeNameCard("j12", "012");
    NameCard * card2 = MakeNameCard("h23", "123");
    NameCard * card3 = MakeNameCard("u34", "234");
    LInsert(&list, card1);
    LInsert(&list, card2);
    LInsert(&list, card3);

    //2.Ư�� �̸��� ������� Ž���� �����Ͽ�, �� ����� ������ ����Ѵ�.
    if(LFirst(&list, &card)){
        int i = NameCompare(card, "h23");
        if(i==0)        //if(!NameCompare(card, "h23"))���ε� �� �� �ִ�. �ؿ��� �׷��� ���.
            ShowNameCardInfo(card);
        else{
            while(LNext(&list, &card)){
                int i = NameCompare(card, "h23");
                if(i==0)
                    ShowNameCardInfo(card);
            }
        }
    }

    //3.Ư�� �̸��� ������� Ž���� �����Ͽ�, �� ����� ��ȭ��ȣ ������ �����Ѵ�.
    if(LFirst(&list, &card)){
        if(!NameCompare(card, "j12"))
            ChangePhoneNum(card, "456");
        else{
            while(LNext(&list, &card)){
                if(!NameCompare(card, "j12"))
                    ChangePhoneNum(card, "456");
            }
        }
    }

    //4.Ư�� �̸��� ������� Ž���� �����Ͽ�, �� ����� ������ �����Ѵ�.
    if(LFirst(&list, &card)){
        if(!NameCompare(card, "u34")){
            card = LRemove(&list);
            free(card);
        }
        else{
            while(LNext(&list, &card)){
                if(!NameCompare(card, "u34")){
                    card = LRemove(&list);
                    free(card);
                }
            }
        }
    }

    //5.������ �����ִ� ��� ����� ��ȭ��ȣ ������ ����Ѵ�.
    printf("���� �������� ��: %d \n", LCount(&list));

    if(LFirst(&list, &card)){
        ShowNameCardInfo(card);

        while(LNext(&list, &card)){
            ShowNameCardInfo(card);
        }
    }

    return 0;
}