#include <bits/stdc++.h>

#define MD 998244353

using namespace std;

typedef long long ll;

ll power(ll base, ll exp) {
	ll ans = 1;
	while (exp > 0) {
		if (exp & 1) ans = ans * base % MD;
		exp >>= 1;
		base = base * base % MD;
	}
	return ans;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ll n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;

	ll ps[m] = {};
	ps[0] = 1;
	for (int i = 1; i < m; ++i) ps[i] = ps[i - 1] + (b[i] == '1' ? 1 : 0);

	ll sm = 0;

	for (int i = 0; i < n; ++i) {
		if (a[i] == '1') {
			ll pw = n - i;
			if (pw > m) continue;
			ll pass = ps[m - pw];
			sm = (sm + power(2, pw - 1) * pass) % MD;
		}
	}

	cout << sm << endl;

    return 0;
}
