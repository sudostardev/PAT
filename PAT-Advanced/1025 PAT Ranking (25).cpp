#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct {
	char id[15];
	int score;
	int lrank;
	int frank;
	int ln;
} Stu;

Stu s[30010];

bool cmp(Stu a, Stu b) {
	if (a.score != b.score) {
		return a.score > b.score;
	}
	else {
		return strcmp(a.id, b.id) < 0;
	}
}

int main() {
	int n, k;
	int num = 0, temp = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &k);
		for (int j = 0; j < k; ++j) {
			scanf("%s %d", s[num].id, &s[num].score);
			s[num].ln = i + 1;
			++num;
		}
		// 内部进行排序
		sort(s + temp, s + num, cmp);

		// 设置内部名次
		int cnt = 1;
		s[temp].lrank = 1;
		for (int j = temp + 1; j < num; ++j) {
			++cnt;
			if (s[j].score != s[j - 1].score) {
				s[j].lrank = cnt;
			}
			else {
				s[j].lrank = s[j - 1].lrank;
			}
		}
		temp = num;
	}

	// 全体排序
	sort(s, s + num, cmp);

	// 设置全体名次
	s[0].frank = 1;
	for (int i = 1; i < num; ++i) {
		if (s[i].score != s[i - 1].score) {
			s[i].frank = i + 1;
		}
		else {
			s[i].frank = s[i - 1].frank;
		}
	}

	printf("%d\n", num);
	for (int i = 0; i < num; ++i) {
		printf("%s %d %d %d\n", s[i].id, s[i].frank, s[i].ln, s[i].lrank);
	}

	return 0;
}