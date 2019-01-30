#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

ld memo[200][200];

ld prob(ld v1, ld v2, ld n) {
	ld ret;
	if (memo[(int)v1][(int)v2] != -1.0) {
		return memo[(int)v1][(int)v2];
	}
	else if (v1 > n / 2) {
		ret = 1.0;
	}
	else if (v2 >= n / 2) {
		ret = 0.0;
	}
	else {
		ret = 0.5 * prob(v1 + 1, v2, n) + 0.5 * prob(v1, v2 + 1, n);
	}
	memo[(int)v1][(int)v2] = ret;
	return ret;
}

int main() {

	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 200; ++i) {
			for (int j = 0; j < 200; ++j) {
				memo[i][j] = -1.0;
			}
		}

		ld n, v1, v2, w;
		cin >> n >> v1 >> v2 >> w;

		if (v2 >= n / 2) cout << "RECOUNT!\n";
		else if (prob(v1, v2, n) > w / 100) cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!\n";
		else cout << "PATIENCE, EVERYONE!\n";
	}

	return 0;
}
