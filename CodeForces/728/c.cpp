#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int fp(int city, int* b, int sz) {
	if (b[0] >= city) return 0;
	int bs = 0;
	for (int j = sz / 2; j; j >>= 1) while (bs + j < sz && b[bs + j] < city) bs += j;
	return bs;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, m;
	cin >> n >> m;
	int a[n], b[m];
	fl (i, 0, n) cin >> a[i];
	fl (i, 0, m) cin >> b[i];

	sort(a, a + n);
	sort(b, b + m);

	int mx = 0;

	fl (i, 0, n) {
		int to = fp(a[i], b, m);
		if (to == m - 1) mx = max(mx, abs(a[i] - b[m - 1]));
		else mx = max(mx, min(abs(a[i] - b[to]), abs(a[i] - b[to + 1])));
	}

	cout << mx << endl;

    return 0;
}
