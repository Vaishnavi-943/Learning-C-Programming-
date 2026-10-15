#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;

    ptr = (int *)malloc(sizeof(int));

    *ptr = 10;

    printf("Before free: %d\n", *ptr);

    free(ptr);

    // ptr is now a dangling pointer
    printf("Pointer is now dangling\n");

    return 0;
}