/*注意换行符，long long的使用*/

#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    long long a, b, c;
    for (int i = 0; i < t; ++i) {
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a + b > c) {
            printf("Case #%d: true", i + 1);
        } else {
            printf("Case #%d: false", i + 1);
        }
    }

    return 0;
}