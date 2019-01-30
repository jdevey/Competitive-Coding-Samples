#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

int main() {

	ll l1, r1, t1, l2, r2, t2;
	cin >> l1 >> r1 >> t1 >> l2 >> r2 >> t2;

	ll g = gcd(t1, t2);

	if (l1 < l2) {
		swap(t1, t2);
		swap(l1, l2);
		swap(r1, r2);
	}

	ll d = l1 - l2;
	ll lo = d - d % g;
	ll hi = lo + g;

	ll los = min(r1, lo + r2) - max(l1, lo + l2) + 1;
	ll his = min(r1, hi + r2) - max(l1, hi + l2) + 1;

	cout << max({los, his, 0ll}) << endl;

    return 0;
}

