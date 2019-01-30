#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	int a[n][n];
	fl (i, 0, n) fl (j, 0, n) cin >> a[i][j];

	vector <int> good;
	fl (i, 0, n) {
		bool g = true;
		fl (j, 0, n) {
			if (a[i][j] == 1 || a[i][j] == 3) g = false;
		}
		if (g) good.push_back(i + 1);
	}
	cout << good.size() << endl;
	for (auto x : good) cout << x << " ";

    return 0;
}
