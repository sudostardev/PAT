/* 纠结在了一个极端情况，n=1，成绩为零，但整个数组数据都为零，
 * 觉得这样的话k向后移动定位错误（煞笔啊人家n=1，k往后移动个毛线），
 * 还用了个变量去记录最大的学校id，作为找最大值时循环的结束条件（简直煞笔）
 * 还想出了一个情况就是若干组值但是最小的就是零，导致k往后移动定位错误
 * （人家踏马求的是最大你想最小的干啥，最大值为0只可能是n=1即只有一所学校的情况）
 * 我踏马就是个智障。
 */

#include <stdio.h>

int a[100010] = {0};

int main() {
    int n, id, sco;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &id, &sco);
        a[id] += sco;
    }

    int max = -1, k = 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > max) {
            max = a[i];
            k = i;
        }
    }
    printf("%d %d", k, max);

    return 0;
}