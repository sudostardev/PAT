#include <stdio.h>
#include <string.h>

int main() {
	char str1[100], str2[100];
	fgets(str1, 99, stdin);
	fgets(str2, 99, stdin);

	int ht1[128] = { 0 };
	int ht2[128] = { 0 };
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	for (int i = 0; i < len1; ++i) {
		ht1[str1[i]] = 1;
		for (int j = 0; j < len2; ++j) {
			if (str1[i] == str2[j]) {
				ht1[str1[i]] = -1;
				break;
			}
		}
		if (ht1[str1[i]] == 1) {
			if (str1[i] >= 'a' && str1[i] <= 'z') {
				str1[i] -= 32;
			}

			if (ht2[str1[i]] == 0) {
				putchar(str1[i]);
				ht2[str1[i]] = 1;
			}
		}
	}

	return 0;
}