#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

map <ll, ll> pf(ll n) {
	map <ll, ll> ret;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			++ret[i];
			n /= i;
			i = 1;
		}
	}
	if (n > 1) ++ret[n];
	return ret;
}

ll nextup(ll n) {
	ll j = 1;
	while (j < n) j <<= 1;
	return j;
}

ll gen(map <ll, ll>& m) {
	ll ret = 1;
	for (auto x : m) ret *= x.first;
	return ret;
}

int main() {

	ll n;
	cin >> n;

	map <ll, ll> m = pf(n);

	ll mf = 1;
	for (auto x : m) mf = max(mf, x.second);

	bool uni = true;
	for (auto x : m) if (x.second != m.begin()->second) uni = false;

	//cout << mf << " " << 31 - __builtin_clz(mf) << endl;
	//for (auto x : m) cout << x.first << "     " << x.second << endl;
	if (__builtin_popcountll(mf) == 1 && uni) {
		cout << gen(m) << " " << 63 - __builtin_clzll(mf) << endl;
	}
	else {
		cout << gen(m) << " " << 63 - __builtin_clzll(nextup(mf)) + 1 << endl;
	}

    return 0;
}
