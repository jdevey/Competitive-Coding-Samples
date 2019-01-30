/*
ID: deveyjo1
TASK: skidesign
LANG: C++14            
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    
	freopen("skidesign.in", "r", stdin);
	freopen("skidesign.out", "w+", stdout);

	int n, mn = 1e9;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];

	sort(a, a + n);

	for (int l = a[0]; l <= 83; ++l) {
		int cost = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] < l) cost += (l - a[i]) * (l - a[i]);
			if (a[i] > l + 17) cost += (a[i] - l - 17) * (a[i] - l - 17);
		}
		mn = min(mn, cost);
	}

	cout << mn << endl;

    return 0;
}
