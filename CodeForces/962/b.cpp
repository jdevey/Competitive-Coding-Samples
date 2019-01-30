#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;

	if (!a && !b) return puts("0");

	int cnt = 0;

	if (s[0] == '.') {
		if (a > b) {
			--a;
			++cnt;
			s[0] = 'a';
		}
		else {
			--b;
			++cnt;
			s[0] = 'b';
		}
	}

	fl (i, 1, n) {
		//cout << i << " " << a << " " << b << " " << cnt << endl;
		if (s[i] == '*') continue;
		if (s[i - 1] == 'a') {
			if (b > 0) {s[i] = 'b'; --b; ++cnt;}
		}
		else if (s[i - 1] == 'b') {
			if (a > 0) {s[i] = 'a'; --a; ++cnt;}
		}
		else if (s[i - 1] == '.' || s[i - 1] == '*') {
			if (a > b) {
				if (a > 0) {s[i] = 'a'; --a; ++cnt;}
			}
			else {
				if (b > 0) {s[i] = 'b'; --b; ++cnt;}
			}
		}
	}

	cout << cnt << endl;

	return 0;
}
