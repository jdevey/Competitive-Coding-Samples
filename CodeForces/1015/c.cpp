#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ll n, m;
	cin >> n >> m;
	ll a[n], b[n];
	ll psa[n] = {}, psb[n] = {};
	fl (i, 0, n) cin >> a[i] >> b[i];

	psa[0] = a[0];
	psb[0] = b[0];
	fl (i, 1, n) psa[i] = psa[i - 1] + a[i];
	fl (i, 1, n) psb[i] = psb[i - 1] + b[i];

	ll diff[n];
	fl (i, 0, n) diff[i] = a[i] - b[i];

	sort(diff, diff + n);

	if (psb[n - 1] > m) return puts("-1");

	ll sm = psa[n - 1];
	//cout << sm << endl;
	for (int i = n - 1; i > -1 ; --i) {
		if (sm <= m) {cout << n - 1 - i << endl; return 0;}
		else sm -= diff[i];
	}

	cout << n << endl;

    return 0;
}
