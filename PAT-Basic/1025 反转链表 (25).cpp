#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

typedef struct {
	string addr;
	int data;
	string next;
} Node;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string first_addr, next, addr;
	int data, n, k;
	Node node;
	unordered_map<string, Node> mp;

	cin >> first_addr >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> addr >> data >> next;
		node.addr = addr;
		node.data = data;
		node.next = next;
		mp[addr] = node;
	}

	vector<Node> a;
	a.push_back(mp[first_addr]);
	int cnt = 1;
	for (int i = 1; i < n; ++i) {
		++cnt;
		a.push_back(mp[a[i - 1].next]);
		if (a[i].next == "-1") {
			break;
		}
	}
	if (cnt != n) {
		n = cnt;
	}

	vector<Node> b;
	int num = k;
	while (num <= n) {
		for (int i = 0; i < k; ++i) {
			int t = num - 1 - i;
			b.push_back(a[t]);
		}
		num += k;
	}

	for (int i = num - k; i < n; ++i) {
		b.push_back(a[i]);
	}

	for (int i = 0; i < n - 1; ++i) {
		b[i].next = b[i + 1].addr;
		cout << b[i].addr << " " << b[i].data
			<< " " << b[i].next << "\n";
	}
	b[n - 1].next = "-1";
	cout << b[n - 1].addr << " " << b[n - 1].data
		<< " " << b[n - 1].next;

	return 0;
}