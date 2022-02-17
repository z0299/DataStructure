#include <stdio.h>
#include <math.h>

int BSearchRecur(int ar[], int first, int last, int target){
    int mid = floor((first+last)/2);
    // int idx = 0;

    if(ar[mid] > target){
        last = mid-1;
        return BSearchRecur(ar, first, last, target);
    }
    else if (ar[mid] < target){
        first = mid+1;
        return BSearchRecur(ar, first, last, target);
    }
    else if (ar[mid] == target)
        return mid;
    else if (first > last)
        return -1;
}

int main(void){
    int array[] = {1,3,5,7,9};

    int idx = BSearchRecur(array, 0, (sizeof(array)/4)-1, 7);

    if(idx == -1)
        printf("target이 없습니다.");
    else
        printf("target이 %d에 있습니다", idx);

    return 0;
}
