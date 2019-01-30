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

	sort(a, a + n);

	ll run = 0;
	int cnt = 0;
	fl (i, 0, n) {
		if (run <= a[i]) {
			++cnt;
			run += a[i];
		}
	}

	cout << cnt << endl;

    return 0;
}
