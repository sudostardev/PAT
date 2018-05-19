#include <stdio.h>

int main() {
    int a1[1005], a2[1005], a3[1005], a4[1005], a5[1005];
    int p1, p2, p3, p4, p5;
    p1 = p2 = p3 = p4 = p5 = 0;

    int n, t;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        if (!(t % 5) && !(t % 2)) {
            a1[p1++] = t;
        }
        if (t % 5 == 1) {
            a2[p2++] = t;
        }
        if (t % 5 == 2) {
            a3[p3++] = t;
        }
        if (t % 5 == 3) {
            a4[p4++] = t;
        }
        if (t % 5 == 4) {
            a5[p5++] = t;
        }
    }

    if (!p1)
        printf("N ");
    else {
        int sum1 = 0;
        for (int i = 0; i < p1; ++i) {
            sum1 += a1[i];
        }
        printf("%d ", sum1);
    }

    if (!p2)
        printf("N ");
    else {
        int sum2 = 0;
        for (int i = 0; i < p2; i += 2) {
            sum2 += a2[i];
        }
        for (int i = 1; i < p2; i += 2) {
            sum2 -= a2[i];
        }
        printf("%d ", sum2);
    }

    if (!p3)
        printf("N ");
    else {
        printf("%d ", p3);
    }

    if (!p4)
        printf("N ");
    else {
        int sum4 = 0;
        for (int i = 0; i < p4; ++i) {
            sum4 += a4[i];
        }
        printf("%.1f ", sum4 * 1.0 / p4);
    }

    if (!p5)
        printf("N");
    else {
        int maxnum = -1;
        for (int i = 0; i < p5; ++i) {
            if (maxnum < a5[i]) {
                maxnum = a5[i];
            }
        }
        printf("%d", maxnum);
    }

    return 0;
}
