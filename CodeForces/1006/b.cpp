#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, k;
	cin >> n >> k;
	pair <int, int> a[n];
	for (int i = 0; i < n; ++i) {cin >> a[i].first; a[i].second = i;}

//	for (int i = 0; i < n; ++i) cout << a[i].first << " " << a[i].second << endl;

	sort(a, a + n, greater<>());

//	for (int i = 0; i < n; ++i) cout << a[i].first << " " << a[i].second << endl;

	vector <pair <int, int>> vp;

	//for (int i = 0; i < k; ++i) cout << a[i].first << " " << a[i].second << endl;
	for (int i = 0; i < k; ++i) vp.push_back({a[i].second, a[i].first});

	sort(vp.begin(), vp.end());

	long long sm = 0;
	for (auto x : vp) sm += x.second;
	//for (auto x : vp) cout << x.first << " " << x.second << endl;
	cout << sm << endl;

	vp.back().first = n - 1;
	//cout << vp.back().first << endl;
	cout << vp[0].first + 1 << " ";
	for (int i = 1; i < vp.size(); ++i) cout << vp[i].first - vp[i - 1].first << " ";

    return 0;
}
