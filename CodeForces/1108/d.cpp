#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

char rep(char a, char b) {
	if (a != 'R' && b != 'R') return 'R';
	if (a != 'B' && b != 'B') return 'B';
	if (a != 'G' && b != 'G') return 'G';
}

int main() {

	int n;
	cin >> n;
	string s;
	cin >> s;

	int cnt = 0;
	fl (i, 0, n - 1) {
		if (s[i] == s[i + 1]) {
			s[i + 1] = rep(s[i], i == n - 2 ? 'Z' : s[i + 2]);
			++cnt;
		}
	}

	cout << cnt << endl << s << endl;

    return 0;
}
