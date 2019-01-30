#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	string s[n];
	int a[n];
	fl (i, 0, n) {
		cin >> s[i] >> a[i];
	}

	map <string, int> m;

	fl (i, 0, n) {
		m[s[i]] += a[i];
	}

	int fx = 0;
	for (auto x : m) fx = max(x.second, fx);

	int mxCnt = 0;
	for (auto x : m) if (x.second == fx) ++mxCnt;

	if (mxCnt == 1) {
		for (auto x : m) if (x.second == fx) {
			cout << x.first;
			return 0;
		}
	}

	map <string, int> mm;
	fl (i, 0, n) {
		mm[s[i]] += a[i];
		if (mm[s[i]] >= fx) {
			cout << s[i];
			return 0;
		}
	}

    return 0;
}
