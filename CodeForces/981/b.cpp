#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, m;
	cin >> n;
	pair <int, int> a[n];
	fl (i, 0, n) cin >> a[i].first >> a[i].second;
	cin >> m;
	pair <int, int> b[m];
	fl (i, 0, m) cin >> b[i].first >> b[i].second;

	map <int, int> mm;
	ll sm = 0;

	fl (i, 0, n) {
		if (mm.find(a[i].first) == mm.end()) mm[a[i].first] = a[i].second;
	}
	fl (i, 0, m) {
		if (mm.find(b[i].first) == mm.end()) mm[b[i].first] = b[i].second;
		else mm[b[i].first] = max(mm[b[i].first], b[i].second);
	}

	for (auto x : mm) sm += x.second;

	cout << sm << endl;

    return 0;
}
