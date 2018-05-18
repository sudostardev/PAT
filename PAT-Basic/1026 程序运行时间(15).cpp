/* 注意round()函数返回类型为double，要进行强制转换
 * printf()函数，%0md占位符的使用
 * 注意要除以100.0而不是100
 */

#include <stdio.h>
#include <math.h>

int main() {
    int c1, c2, h, m, s;
    scanf("%d %d", &c1, &c2);

    s = (int)round((c2 - c1) / 100.0);

    h = s / 3600;
    s = s % 3600;

    m = s / 60;
    s = s % 60;

    printf("%02d:%02d:%02d", h, m, s);

    return 0;
}