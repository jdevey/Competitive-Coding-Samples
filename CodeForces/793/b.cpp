#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, m;
	cin >> n >> m;
	string a[n];
	fl (i, 0, n) cin >> a[i];

	int** dp = new int*[n];
	fl (i, 0, n) dp[i] = new int[n];

	fl (i, 0, n) fl (j, 0, m) dp[i][j] = 1e9;

	int Sx, Sy, Tx, Ty;
	fl (i, 0, n) fl (j, 0, m) {
		if (a[i][j] == 'S') {
			Sx = j;
			Sy = i;
		}
		if (a[i][j] == 'T') {
			Tx = j;
			Ty = i;
		}
	}

	queue <pair <int, int>> qp;
	qp.insert({Sy, Sx});
	dp[Sy][Sx] = 0;

	while (!qp.empty()) {
		
	}

    return 0;
}
