#include <stdio.h>

void HanoiTowerMove(int num, char a, char b, char c){
    if(num==1){
        printf("원반 1을 %c에서 %c로 이동\n", a, c);  //마지막 원반을 C로 옮김
    }
    else{
        HanoiTowerMove(num-1, a, c, b);  //n-1개의 원반을 A에서 B로 옮겨야 가장 큰 원반을 A에서 C로 옮길 수 있다.
        printf("원반 %d를 %c에서 %c로 이동\n", num, a, c);  //가장 큰 원반을 A에서 C로 옮긴다.
        HanoiTowerMove(num-1, b, a, c);  //A에서 B로 옮겨졌던 n-1개의 원반을 B에서 C로 옮긴다.
    }
}

int main(void){
    //막대 A의 원반 3개를 막대 B를 경유하여 막대 C로 옮기기
    HanoiTowerMove(3, 'A', 'B', 'C');

    return 0;
}