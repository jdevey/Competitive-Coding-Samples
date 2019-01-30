#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {

	int q;
	cin >> q;
	while (q--) {
		ll x, y, k, m;
		cin >> x >> y >> k;
		x = abs(x);
		y = abs(y);
		m = min(x, y);
		ll total = m + (x - m) + (y - m);
		if (total > k) {
			cout << -1 << endl;
			continue;
		}
		ll pp = (x + y) & 1;
		ll mp = k & 1;
		ll maxp = max(x, y) & 1;
		if (pp & mp) cout << k - 1 << endl;
		else if (!pp & mp) cout << k - 2 * (mp != maxp) << endl;
		else if (pp & !mp) cout << k - 1 << endl;
		else cout << k - 2 * (mp != maxp)  << endl;
	}

    return 0;
}
