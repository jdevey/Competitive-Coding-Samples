#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ll n, k;
	cin >> n >> k;
	ll a[n];
	fl (i, 0, n) cin >> a[i];

	ll md = a[0] % k;
	fl (i, 0, n) if (a[i] % k != md) return puts("-1");

	ll mn = 1e9, sm = 0;
	fl (i, 0, n) mn = min(mn, a[i]);

	fl (i, 0, n) sm += a[i] - mn;

	cout << sm / k << endl;

    return 0;
}
