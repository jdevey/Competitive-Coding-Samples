#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	int a[n], b[n];
	fl (i, 0, n) cin >> a[i];
	fl (i, 0, n) cin >> b[i];

	int dp[n] = {}, gm = 1e9;
	dp[0] = 1e9;

	fl (i, 0, n) {
		int rn = 1e9;
		for (int j = i - 1; j > -1; --j) {
			if (a[j] < a[i]) {
				rn = min(rn, b[i] + b[j]);
			}
		}
		dp[i] = rn;
	}

	fl (i, 0, n) {
		int rn = 1e9;
		for (int j = i - 1; j > -1; --j) {
			if (a[j] < a[i]) {
				rn = min(rn, b[i] + dp[j]);
			}
		}
		gm = min(gm, rn);
	}

	cout << (gm >= (int)1e9 ? -1 : gm) << endl;

    return 0;
}
