#include <bits/stdc++.h>

#define F first
#define S second
#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, k;
	scanf("%d %d", &n, &k);
	pair <int, int> a[n];
	fl (i, 0, n) {scanf("%d", &a[i].F); a[i].S = i;}

	ll cost = 0;
	int ans[n], nx = k;
	bool ts[n + k] = {};

	sort(a, a + n, greater <>());

	fl (i, 0, n) {
		if (a[i].S < nx) ans[a[i].S] = nx + 1;
		else ans[a[i].S] = a[i].S + 1;
		cost += a[i].S < nx ? (ll)a[i].F * (nx - a[i].S) : 0;
		ts[a[i].S < nx ? nx : a[i].S] = true;
		for (int j = nx; ts[j]; ++j) ++nx;
	}

	printf("%lld\n", cost);
	fl (i, 0, n) printf("%d ", ans[i]);

	return 0;
}

