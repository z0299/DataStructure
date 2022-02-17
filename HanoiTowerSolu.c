#include <stdio.h>

void HanoiTowerMove(int num, char a, char b, char c){
    if(num==1){
        printf("���� 1�� %c���� %c�� �̵�\n", a, c);  //������ ������ C�� �ű�
    }
    else{
        HanoiTowerMove(num-1, a, c, b);  //n-1���� ������ A���� B�� �Űܾ� ���� ū ������ A���� C�� �ű� �� �ִ�.
        printf("���� %d�� %c���� %c�� �̵�\n", num, a, c);  //���� ū ������ A���� C�� �ű��.
        HanoiTowerMove(num-1, b, a, c);  //A���� B�� �Ű����� n-1���� ������ B���� C�� �ű��.
    }
}

int main(void){
    //���� A�� ���� 3���� ���� B�� �����Ͽ� ���� C�� �ű��
    HanoiTowerMove(3, 'A', 'B', 'C');

    return 0;
}