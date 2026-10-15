#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;

    int *ptr = (int *)malloc(n * sizeof(int));

    ptr[0] = 1;

    printf("%d\n", ptr[0]);

    free(ptr);

    return 0;
}