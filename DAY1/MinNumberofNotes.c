#include<stdio.h>

int main(){
    int notes[]={100,50,20,10,5,2,1};
    int N=242;
    int size=sizeof(notes)/4;
    int count=0;
    for(int i=0;i<size;i++){
        //Division modulus
        if(N==0){
            break;
        }
        int q=N/notes[i];
        N=N%notes[i];
        count+=q;

    }
    printf("Minimum number of notes required is %d",count);
    
}