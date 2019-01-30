#include <iostream>
#include <algorithm>

#define fl(i, a, b) for (int (i) = (a); (i) < (b); ++(i))

using namespace std;

typedef long long ll;

ll compTime(int* a, int n, int rk) {
	ll s = 0;
	fl (i, 0, n) s += a[i] / rk + (bool)(a[i] % rk);
	return s;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int t, n, h;
	cin >> t;

	while (t--) {
		cin >> n >> h;

		int a[n];
		fl (i, 0, n) cin >> a[i];

		int mx = 0;
		fl (i, 0, n) mx = max(mx, a[i]);

		int rk = 0;
		for (int i = mx / 2; i >= 1; i >>= 1) while (rk + i <= mx && compTime(a, n, rk + i) > h) rk += i;

		cout << rk + 1 << endl;
	}

	return 0;
}
