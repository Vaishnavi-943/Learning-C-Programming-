#include <stdio.h>
#include <stdlib.h>

struct Sensor {
    int id;
    int type;

    union Reading {
        int temperature;
        float pressure;
        float humidity;
    } data;
};

int main() {
    int n, i;

    scanf("%d", &n);

    if (n <= 0) {
        printf("INVALID COUNT\n");
        return 0;
    }

    struct Sensor *s =
        (struct Sensor *)malloc(n * sizeof(struct Sensor));

    if (s == NULL) {
        return 1;
    }

    for (i = 0; i < n; i++) {
        scanf("%d %d", &s[i].id, &s[i].type);

        if (s[i].type == 1) {
            scanf("%d", &s[i].data.temperature);
        } else if (s[i].type == 2) {
            scanf("%f", &s[i].data.pressure);
        } else if (s[i].type == 3) {
            scanf("%f", &s[i].data.humidity);
        }
    }

    for (i = 0; i < n; i++) {
        printf("Sensor %d: ", s[i].id);

        if (s[i].type == 1) {
            printf("Temperature = %d\n",
                   s[i].data.temperature);
        } else if (s[i].type == 2) {
            printf("Pressure = %.2f\n",
                   s[i].data.pressure);
        } else if (s[i].type == 3) {
            printf("Humidity = %.2f\n",
                   s[i].data.humidity);
        } else {
            printf("INVALID TYPE\n");
        }
    }

    free(s);
    return 0;
}
