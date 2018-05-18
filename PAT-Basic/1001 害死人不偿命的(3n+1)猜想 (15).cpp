/*当n = 1时，应直接输出0*/

#include <stdio.h>

int main() {
    int n;
    int cnt = 0;
    scanf("%d", &n);

    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = (3 * n + 1) / 2;
        }
        ++cnt;
    }
    printf("%d", cnt);

    return 0;
}