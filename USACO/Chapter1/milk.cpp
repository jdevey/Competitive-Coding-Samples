/*
ID: deveyjo1
TASK: milk
LANG: C++14            
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    
	freopen("milk.in", "r", stdin);
	freopen("milk.out", "w+", stdout);

	int n, m;
	cin >> n >> m;

	pair <int, int> a[m];
	for (int i = 0; i < m; ++i) cin >> a[i].first >> a[i].second;

	sort(a, a + m);

	int cost = 0;

	for (int i = 0; i < m; ++i) {
		cost += min(n, a[i].second) * a[i].first;
		n -= min(n, a[i].second);
		if (n == 0) break;
	}

	cout << cost << endl;

    return 0;
}
