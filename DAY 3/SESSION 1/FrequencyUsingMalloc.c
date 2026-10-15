#include<stdio.h>
#include<stdlib.h>

int main(){
    int *freq = (int *)malloc(10* sizeof(int));
    for(int i = 0; i < 10; i++){
        freq[i] = 0;
    }
    free(freq);
    return 0;
}     