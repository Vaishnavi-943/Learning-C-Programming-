#include <stdio.h>
#include <stdlib.h>

struct Ticket {
    int ticketNo;
    char vehicleNo[20];
    double gross;
    double tare;
    double net;
};

void calculateNet(struct Ticket *t) {
    t->net = t->gross - t->tare;
}

void displayTicket(struct Ticket *t) {
    printf("%d %s gross %.2lf tare %.2lf\n",
           t->ticketNo, t->vehicleNo, t->gross, t->tare);
    printf("net %.2lf\n", t->net);
}

int main() {
    int choice, n, i, heaviest = 0;
    double total = 0.0;

    scanf("%d %d", &choice, &n);

    if (n <= 0) {
        printf("INVALID COUNT\n");
        return 0;
    }

    struct Ticket *t =
        (struct Ticket *)malloc(n * sizeof(struct Ticket));

    if (t == NULL) {
        return 1;
    }

    for (i = 0; i < n; i++) {
        scanf("%d %19s %lf %lf",
              &t[i].ticketNo,
              t[i].vehicleNo,
              &t[i].gross,
              &t[i].tare);

        calculateNet(&t[i]);
        total += t[i].net;

        if (i == 0 || t[i].net > t[heaviest].net) {
            heaviest = i;
        }
    }

    printf("WEIGHBRIDGE DAY BOOK\n");

    for (i = 0; i < n; i++) {
        displayTicket(&t[i]);
    }

    printf("Tickets: %d\n", n);
    printf("Total net weight (kg): %.2lf\n", total);

    printf("Heaviest net load: ticket %d %s\n",
           t[heaviest].ticketNo,
           t[heaviest].vehicleNo);
    printf("%.2lf\n", t[heaviest].net);

    free(t);

    return 0;
}
