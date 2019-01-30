#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void an(string& s, int* ans, int sz, int ind, bool flip) {
	if (ind < 2) return;
	ans[ind] = flip ? s[ind] == 'b' : s[ind] == 'a';
	an(s, ans, sz, ind - 1, s[ind] == 'a');
}

int main() {

	string s;
	cin >> s;

	int sz = s.size();
	int ans[sz] = {};

	ans[sz - 1] = s.back() == 'a';
	for (int i = sz - 2; i > -1; --i) ans[i] = s[i] != s[i + 1];

	for (int i = 0; i < sz; ++i) cout << ans[i] << " ";

	return 0;
}
