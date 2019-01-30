#include <bits/stdc++.h>

using namespace std;

bool isLower(char c) {
	return c >= 'a' && c <= 'z';
}

bool isUpper(char c) {
	return c >= 'A' && c <= 'Z';
}

bool isNum(char c) {
	return c >= '0' && c <= '9';
}

int trans(char c) {
	if (isLower(c)) return 0;
	if (isUpper(c)) return 1;
	if (isNum(c)) return 2;
}

int rt(int n) {
	if (n == 0) return 'a';
	if (n == 1) return 'A';
	if (n == 2) return '0';
}

int fz(int* cnt) {
	for (int i = 0; i < 3; ++i) {
		if (!cnt[i]) return i;
	}
	return -1;
}

int main() {

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int cnt[3] = {};
		for (auto c : s) ++cnt[trans(c)];
		for (int i = 0; i < s.size(); ++i) {
			if (cnt[trans(s[i])] > 1 && fz(cnt) != -1) {
				--cnt[trans(s[i])];
				s[i] = rt(fz(cnt));
				++cnt[fz(cnt)];
			}
		}
		cout << s << endl;
	}

    return 0;
}
