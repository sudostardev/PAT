#include <stdio.h>

int main() {
	int ht[128] = { 0 };
	char c;
	while ((c = getchar()) != '\n') {
		if (c >= 'A' && c <= 'Z') {
			c += 32;
		}
		if (c >= 'a' && c <= 'z') {
			++ht[c];
		}
	}

	int ma = 'a';
	for (int i = 'b'; i <= 'z'; ++i) {
		if (ht[i] > ht[ma]) {
			ma = i;
		}
	}

	printf("%c %d", ma, ht[ma]);

	return 0;
}