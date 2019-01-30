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
	int a[n];
	fl (i, 0, n) cin >> a[i];

	if (n < 3) return puts("0");

	int mn = 1000000000;

	for (int i = -1; i < 2; ++i) {
		for (int j = -1; j < 2; ++j) {
			int total = abs(i) + abs(j), diff = (a[1] + j) - (a[0] + i), curr = a[1] + j;
			bool good = true;
			for (int k = 2; k < n; k++) {
				curr += diff;
				if (abs(a[k] - curr) > 1) {good = false; break;}
				else total += abs(a[k] - curr);
			}
			if (!good) continue;
			mn = min(mn, total);
		}
	}

	if (mn == 1000000000) return puts("-1");
	cout << mn << endl;

    return 0;
}
