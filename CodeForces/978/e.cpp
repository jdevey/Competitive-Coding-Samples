#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, w;
	cin >> n >> w;
	int a[n];
	fl (i, 0, n) cin >> a[i];

	int ps[n];
	ps[0] = a[0];
	fl (i, 1, n) ps[i] = ps[i - 1] + a[i];

	int mn = 2000000000, mx = -2000000000;
	fl (i, 0, n) {
		mn = min(mn, ps[i]);
		mx = max(mx, ps[i]);
	}

	mn = min(mn, 0);
	mx = max(mx, 0);

	if (abs(mx - mn) > w) return puts("0");
	cout << w - abs(mx - mn) + 1 << endl;

    return 0;
}
