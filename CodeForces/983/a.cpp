#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

ll mult(ll r, ll q, ll b) {
	while (r <= q) r *= b;
	return r;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ll n, p, q, b;
	cin >> n;

	while (n--) {
		cin >> p >> q >> b;
		set <ll> s;

		while (true) {
			ll r = p % q;
			if (r % b == 0) {
				cout << "Finite" << endl;
				break;
			}
			p = mult(r, q, b);
			if (s.find(p) != s.end()) {
				cout << "Infinite" << endl;
				break;
			}
			s.insert(p);
		}
	}

    return 0;
}
