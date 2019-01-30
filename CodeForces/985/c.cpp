#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

void inc(int& ind, int k) {
	--ind;
	if (ind % k == 0) --ind;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, k, l;
	cin >> n >> k >> l;
	int nk = n * k;
	int a[nk];
	fl (i, 0, nk) cin >> a[i];

	sort(a, a + nk);
/*
	if (k == 1) {
		if (a[nk - 1] - a[0] > l) return puts("0");

	}
*/
	int ind = upper_bound(a, a + nk, a[0] + l) - a - 1;

	//cout << ind << endl;

	bool used[nk] = {};

	for (int i = k; i < nk; i += k) {
		if (a[i] - a[0] > l) {
			if (used[ind] || ind % k == 0) {
				inc(ind, k);
			}
			if (ind < 1) return puts("0");
			used[ind] = true;
			swap(a[ind], a[i]);
		}
	}

	ll sm = 0;
	for (int i = 0; i < nk; i += k) {
		sm += a[i];
	}

	cout << sm << endl;

    return 0;
}
