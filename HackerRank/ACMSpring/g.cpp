#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int a[9][9], n, m;
bool vis[10001] = {};

void rec(bool& good, int col) {
	if (col == m) {good = true; return;}
	fl (i, 0, n) {
		if (!vis[a[i][col]]) {
			vis[a[i][col]] = true;
			rec(good, col + 1);
			vis[a[i][col]] = false;
		}
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	cin >> n >> m;
	fl (i, 0, n) fl (j, 0, m) cin >> a[i][j];

	if (!n || !m) return puts("Yes");

	bool good = false;

	fl (i, 0, n) {
		vis[a[i][0]] = true;
		rec(good, 1);
		vis[a[i][0]] = false;
	}

	cout << (good ? "Yes" : "No") << endl;

    return 0;
}
