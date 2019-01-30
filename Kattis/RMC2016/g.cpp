#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

	ll n, m;
	cin >> n >> m;
	ll a[n][m];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	ll ps[n][m];
	ps[0][0] = a[0][0];
	for (int i = 1; i < m; ++i) ps[0][i] = ps[0][i - 1] + a[0][i];
	for (int i = 1; i < n; ++i) ps[i][0] = ps[i - 1][0] + a[i][0];

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			ps[i][j] = max(ps[i - 1][j], ps[i][j - 1]) + a[i][j];
		}
	}

	for (int i = 0; i < n; ++i) cout << ps[i][m - 1] << " ";

	return 0;
}
