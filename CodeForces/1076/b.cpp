#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))
#define UPLIM 100010

using namespace std;

typedef long long ll;
typedef long double ld;

void erat(bool* a) {
	for (ll i = 2; i < UPLIM; ++i) for (ll j = a[i] ? UPLIM : 2 * i; j < UPLIM; j += i) a[j] = true;
}

ll fp(bool* a, ll n) {
	for (ll i = 2; i * i <= n; ++i) {
		if (n % i == 0 && !a[i]) return i;
	}
	return n;
}

int main() {

	bool p[100003] = {};
	erat(p);

	ll n;
	cin >> n;

	ll cnt = 0;

	while (n) {
		if (~n & 1) {
			cnt += n / 2;
			break;
		}
		else {
			n -= fp(p, n);
			++cnt;
		}
	}

	cout << cnt << endl;

    return 0;
}
