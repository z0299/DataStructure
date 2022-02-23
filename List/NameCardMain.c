#include <stdio.h>
#include <stdlib.h>
#include "NameCard.c"
#include "ArrayList.c"

int main(void){
    List list;
    NameCard * card;

    ListInit(&list);

    //1.총 3명의 전화번호 정보를, 앞서 우리가 구현한 리스트에 저장한다.
    NameCard * card1 = MakeNameCard("j12", "012");
    NameCard * card2 = MakeNameCard("h23", "123");
    NameCard * card3 = MakeNameCard("u34", "234");
    LInsert(&list, card1);
    LInsert(&list, card2);
    LInsert(&list, card3);

    //2.특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보를 출력한다.
    if(LFirst(&list, &card)){
        int i = NameCompare(card, "h23");
        if(i==0)        //if(!NameCompare(card, "h23"))으로도 할 수 있다. 밑에서 그렇게 사용.
            ShowNameCardInfo(card);
        else{
            while(LNext(&list, &card)){
                int i = NameCompare(card, "h23");
                if(i==0)
                    ShowNameCardInfo(card);
            }
        }
    }

    //3.특정 이름을 대상으로 탐색을 진행하여, 그 사람의 전화번호 정보를 변경한다.
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

    //4.특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보를 삭제한다.
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

    //5.끝으로 남아있는 모든 사람의 전화번호 정보를 출력한다.
    printf("현재 데이터의 수: %d \n", LCount(&list));

    if(LFirst(&list, &card)){
        ShowNameCardInfo(card);

        while(LNext(&list, &card)){
            ShowNameCardInfo(card);
        }
    }

    return 0;
}