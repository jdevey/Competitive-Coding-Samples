#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, u;
	cin >> n >> u;
	int a[n];
	fl (i, 0, n) cin >> a[i];

	ld mx = -1.0;

	for (int l = 0, r = 2; l < n - 2; ++l) {
		for (r = max(r, l + 2); r < n - 1 && a[r + 1] - a[l] <= u; ++r);
		if (a[r] - a[l] > u) continue;
		mx = max(mx, (ld)(a[r] - a[l + 1]) / (a[r] - a[l]));
	}

	if (mx == -1.0) cout << -1 << endl;
	else cout << fixed << setprecision(16) << mx << endl;

    return 0;
}
