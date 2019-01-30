#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

bool allValid(int lowLim, int upLim, int n) {
	int base = (n - 1) / lowLim + 1;
	for (int i = lowLim + 1; i <= upLim; ++i) if ((n - 1) / i + 1 != base) return false;
	return true;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, m;
	cin >> n >> m;
	if (!m && n == 1) {
		cout << 1;
		return 0;
	}
	if (!m) {
		cout << -1;
		return 0;
	}
	pair <int, int> a[m];
	fl (i, 0, m) cin >> a[i].first >> a[i].second;

	int upLim = 101, lowLim = 0;

	fl (i,0, m) {
		if (a[i].second > 1) upLim = min(upLim, (a[i].first - 1) / (a[i].second - 1));
		lowLim = max(lowLim, (a[i].first - 1) / a[i].second + 1);
		//cout << i << " " << lowLim << " " << upLim << endl;
	}

	cout << (allValid(lowLim, upLim, n) ? (n - 1) / lowLim + 1 : -1);

	return 0;
}

