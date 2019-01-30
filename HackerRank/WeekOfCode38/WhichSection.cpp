#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, n, m, k, x, ans;
	cin >> t;
	while (t--) {
		cin >> n >> k >> m;
		int a[m];
		for (int i = 0; i < m; ++i) cin >> a[i];
		for (int i = 1, cnt = 0; i <= m; ++i) {
			cnt += a[i - 1];
			if (cnt >= k) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}
