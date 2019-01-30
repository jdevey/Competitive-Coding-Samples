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
	int a[n];
	fl (i, 0, n) cin >> a[i];

	map <ll, int> m;

	fl (i, 0, n) ++m[a[i]];

	ll cnt = 0;
	fl (i, 0, n) {
		int seek = 32 - __builtin_clz(a[i]);
		while ((1ll << seek) <= 1e10) {
			auto it = m.find((1ll << seek) - a[i]);
			if (it != m.end()) {
				cnt += it->second;
				if (it->first == a[i]) --cnt;
			}
			++seek;
		}
	}

	cout << cnt / 2;

    return 0;
}
