#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))
using namespace std;
typedef long long ll;
typedef long double ld;

ll cel(ll a, ll b) {
    return (a - 1) / b + 1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	
	ll t;
	cin >> t;

	while (t--) {
	    ll n, x, y, d;
	    cin >> n >> x >> y >> d;

	    if (abs(y - x) % d == 0) {
	        cout << abs(y - x) / d << endl;
	        continue;
	    }

	    if (y % d != 1 && (n - y) % d != 0) {
	        cout << -1 << endl;
	        continue;
	    }

	    ll mn = 1e18;
	    if (y % d == 1) mn = min(mn, cel((x - 1), d) + (y - 1) / d);
	    if ((n - y) % d == 0) mn = min(mn, cel((n - x), d) + (n - y) / d);

	    cout << mn << endl;
	}
	
    return 0;
}
