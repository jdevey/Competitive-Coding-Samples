#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, m, b1, b2, d;
	cin >> n >> m;
	int a[n], ps[n];
	fl (i, 1, n) cin >> a[i];
	ps[0] = 0;
	fl (i, 1, n) ps[i] = ps[i - 1] + a[i];

	int mn = ps[n - 1];

	while (m--) {
		cin >> b1 >> b2 >> d;
		mn = min(mn, d + ps[n - 1] - ps[b2 - 1] + ps[b1 - 1]);
	}

	cout << mn;

    return 0;
}
