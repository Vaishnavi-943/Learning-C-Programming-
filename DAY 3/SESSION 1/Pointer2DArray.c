#include<stdio.h>

int main(){
    int arr[2][3]={
        {10,20,30},
        {40,50,60}
    };
    int (*p)[3]=arr;
    printf("%d\n",p[1][2]);
    printf("%d\n",*(*(arr+1)+1));
    
}