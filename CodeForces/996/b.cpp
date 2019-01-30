#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int cel(int a, int b) {
	if (a == 0) return 0;
	return (a - 1) / b + 1;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	int a[n];
	fl (i, 0, n) cin >> a[i];
	pair <int, int> ans[n];

	fl (i, 0, n) ans[i] = {cel(max(a[i] - i, 0), n), i};

	fl (i, 0, n) cout << ans[i].first << " " << ans[i].second << endl;

	sort(ans, ans + n);

	cout << ans[0].second + 1 << endl;

    return 0;
}
