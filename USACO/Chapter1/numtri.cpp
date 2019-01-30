/*
ID: deveyjo1
TASK: numtri
LANG: C++14            
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("numtri.in", "r", stdin);
	freopen("numtri.out", "w+", stdout);
	int n, mx = 0;
	scanf("%d", &n);
	int dp[n][n] = {};
	scanf("%d", &dp[0][0]);
	for (int i = 1; i < n; ++i) {
		int temp;
		for (int j = 0; j <= i; ++j) {
			scanf("%d", &temp);
			dp[i][j] = temp + max(j > 0 ? dp[i - 1][j - 1] : 0, j < i ? dp[i - 1][j] : 0);
		}
	}
	for_each(dp[n - 1], dp[n - 1] + n, [&mx](int elem){mx = max(mx, elem);});
	cout << mx << endl;
	return 0;
}
