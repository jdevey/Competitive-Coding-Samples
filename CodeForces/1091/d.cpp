#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))
#define MD 998244353

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {

	ll n;
	cin >> n;

	ll fac[n + 1];
	fac[0] = 1;
	fl (i, 1, n + 1) fac[i] = fac[i - 1] * i % MD;

	ll invfac[n + 1];
	invfac[n] = n;
	for (ll i = n - 1; i > 0; --i) invfac[i] = invfac[i + 1] * i % MD;

	ll total = fac[n];

	fl (i, 1, n + 1) {
		total = (total + fac[n] - invfac[i]) % MD;
		if (total < 0) total += MD;
	}

	cout << total << endl;

    return 0;
}
