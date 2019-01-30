#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, m;
	cin >> n >> m;
	pair <int, int> a[m];
	fl (i, 0, m) cin >> a[i].first >> a[i].second;

	if (n < 3) return puts("0");

	bool rows[n] = {}, cols[n] = {};
	
	rows[0] = true; rows[n - 1] = true;
	cols[0] = true; cols[n - 1] = true;

	fl (i, 0, m) {
		cols[a[i].first - 1] = true;
		rows[a[i].second - 1] = true;
	}

	int cnt = 0;
	fl (i, 0, n) {
		if (!rows[i]) ++cnt;
		if (!cols[i]) ++cnt;
	}

	if (n & 1 && !rows[n / 2] && !cols[n / 2]) --cnt;

	cout << cnt << endl;

    return 0;
}
