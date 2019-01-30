#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int a[351][351], dp[351][351], n;
bool used[351][351] = {};


int findSurrMax(int xPos, int yPos) {
	int mx = 0;
	if (xPos > 0) mx = max(mx, dp[yPos][xPos - 1]);
	if (xPos < n - 1) mx = max(mx, dp[yPos][xPos + 1]);
	if (yPos > 0) mx = max(mx, dp[yPos - 1][xPos]);
	if (yPos < n - 1) mx = max(mx, dp[yPos + 1][xPos]);
	return mx;
}

/*
void rec(int xPos, int yPos, int& gp) {
	dp[yPos][xPos] = a[yPos][xPos] + findSurrMax(xPos, yPos);
	gp = max(gp, dp[yPos][xPos]);
	if (xPos > 0) rec(xPos - 1, yPos, gp);
	if (xPos < n - 1) rec(xPos + 1, yPos, gp);
	if (yPos > 0) rec(xPos, yPos - 1, gp);
	if (yPos < n - 1) rec(xPos, yPos + 1, gp);
}
*/
int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	cin >> n;
	fl (i, 0, n) fl (j, 0, n) cin >> a[i][j];

	int gp = 0;

	queue <pair <int, int>> qp;
	used[n / 2][n / 2] = true;
	qp.push({n / 2, n / 2});

	while (!qp.empty()) {
		int xPos = qp.front().second, yPos = qp.front().first;
		dp[yPos][xPos] = a[yPos][xPos] + findSurrMax(xPos, yPos);
		gp = max(gp, dp[yPos][xPos]);
		if (xPos > 0 && !used[yPos][xPos - 1]) {qp.push({yPos, xPos - 1}); used[yPos][xPos - 1] = true;}
		if (xPos < n - 1 && !used[yPos][xPos + 1]) {qp.push({yPos, xPos + 1}); used[yPos][xPos + 1] = true;}
		if (yPos > 0 && !used[yPos - 1][xPos]) {qp.push({yPos - 1, xPos}); used[yPos - 1][xPos] = true;}
		if (yPos < n - 1 && !used[yPos + 1][xPos]) {qp.push({yPos + 1, xPos}); used[yPos + 1][xPos] = true;}
		qp.pop();
	}

	cout << gp << endl;

	return 0;
}
