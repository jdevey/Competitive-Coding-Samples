#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, q;
	cin >> n >> q;
	int a[n];
	fl (i, 0, n) cin >> a[i];

	ll prefSum[n] = {};
	prefSum[0] = a[0];
	fl (i, 1, n) prefSum[i] = prefSum[i - 1] + a[i];

	ll currArrow = 0;

	while (q--) {
		ll arrow;
		cin >> arrow;
		currArrow += arrow;

		if (currArrow >= prefSum[n - 1]) {
			currArrow = 0;
			cout << n << endl;
		}
		else {
			int pos = upper_bound(prefSum, prefSum + n, currArrow) - prefSum;
			cout << n - pos << endl;
		}
	}

    return 0;
}
