#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

ll tri(ll n) {
	return n * (n + 1) / 2;
}

ll bef(ll n) {
	return 2 * tri(n / 2) - (2 * tri((n + 1) / 2) - (n + 1) / 2);
}

int main() {

	ll q;
	cin >> q;
	while (q--) {
		ll l, r;
		cin >> l >> r;
		cout << bef(r) - bef(l - 1) << endl;
	}

    return 0;
}
