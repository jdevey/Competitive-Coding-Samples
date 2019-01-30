#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int ct(int* a, int n, int ind) {
	int cnt = 0;
	for (int i = ind; i < n; ++i) {
		if (a[i] == a[ind]) ++cnt;
		else return cnt;
	}
	return cnt;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, k;
	cin >> n >> k;
	int a[n];
	fl (i, 0, n) cin >> a[i];

	sort(a, a + n);

	if (k == 0) {
		if (a[0] == 1) cout << -1;
		else cout << 1;
		return 0;
	}

	for (int i = 0; i < n; i += ct(a, n, i)) {
		int inc = ct(a, n, i);
		if (i + inc == k) {
			cout << a[i];
			return 0;
		}
		else if (i + inc > k) {
			cout << -1;
			return 0;
		}
	}

	if (a[n - 1] == 1000000000) cout << -1;
	else cout << 1000000000;

    return 0;
}
