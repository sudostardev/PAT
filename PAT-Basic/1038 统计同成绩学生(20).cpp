#include <stdio.h>

int main() {
	int n, score;
	int ht[105] = { 0 };

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &score);
		++ht[score];
	}

	scanf("%d %d", &n, &score);
	printf("%d", ht[score]);
	for (int i = 1; i < n; ++i) {
		scanf("%d", &score);
		printf(" %d", ht[score]);
	}

	return 0;
}