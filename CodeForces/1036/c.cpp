#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

ll fac[20] = {};

ll nck(ll n, ll k) {
	return fac[n] / fac[k] / fac[n - k];
}
/*
ll l10(ll n) {
	return nck(n, 3) * 9 * 9 * 9 + nck(n, 2) * 9 * 9 + n * 9 + 1;
}
*/
ll lk10(ll k, ll n) {
	return nck(n, 3) * 9 * 9 * 9 + nck(n, 2) * 9 * 9 + n * 9 + 1 + (k - 1) * (nck(n, 2) * 9 * 9 + n * 9 + 1);
}

ll gc(s) {
	ll ans = 0;
	ll sz = s.size();
	fl (i, 0, sz) {
		if (s[i] != '0') {
			ans += lk10(s[i] - '0', sz - i - 1);
		}
	}
	return ans;
}

int main() {

	fac[0] = 1; fac[1] = 1;
	for (int i = 2; i < 20; ++i) fac[i] = i * fac[i - 1];

	ll n, m;
	cin >> n >> m;

	cout << gc(to_string(n)) - gc(to_string(m - 1)) << endl;

    return 0;
}
