#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ll n;
	cin >> n;
	ll a[n];
	map <ll, ll> m;
	fl (i, 0, n) {
		cin >> a[i];
		m[a[i]] = i;
	}

	sort(a, a + n);
	set <ll> s;
	fl (i, 0, n) s.insert(a[i]);

	fl (i, 0, n) {
		for (ll j = 1; j < 1LL << 33; j <<= 1) {
			if (s.find(a[i] + j) != s.end() && s.find(a[i] - j) != s.end()) {
				cout << 3 << endl;
				cout << *s.find(a[i] - j) << " " << a[i] << " " << *s.find(a[i] + j) << endl;
				return 0;
			}
		}
	}

	fl (i, 0, n) {
		for (ll j = 1; j < 1LL << 33; j <<= 1) {
			if (s.find(a[i] + j) != s.end()) {
				cout << 2 << endl;
				cout << a[i] << " " << *s.find(a[i] + j) << endl;
				return 0;
			}
		}
	}

	cout << 1 << endl << a[0] << endl;

    return 0;
}

