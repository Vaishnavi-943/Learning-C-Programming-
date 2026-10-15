#include <stdio.h>

struct Address {
    char village[100];
    double shareCapital;
};

struct Member {
    int id;
    char name[100];
    double shareCapital;
    struct Address address;
};

int main() {
    struct Member arr[100];
    int n, i;
    double total = 0;

    printf("Enter the number of members: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i].id);
        scanf("%99s", arr[i].name);
        scanf("%lf", &arr[i].shareCapital);
        scanf("%99s", arr[i].address.village);
        scanf("%lf", &arr[i].address.shareCapital);

        total = total + arr[i].shareCapital;
    }

    printf("Total Share Capital = %.2lf\n", total);

    return 0;
}
