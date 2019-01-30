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
	int a[m][n];
	fl (i, 0, m) fl (j, 0, n) cin >> a[i][j];

	map <int, int> win;

	fl (i, 0, m) {
		int mx = 0, mxInd = 1;
		fl (j, 0, n) if (a[i][j] > mx) {
			mx = a[i][j];
			mxInd = j + 1;
		}
		++win[mxInd];
	}

	pair <int, int> mxx;
	mxx.first = 1; mxx.second = 0;
	for (auto x : win) if (x.second > mxx.second) {
		mxx.first = x.first;
		mxx.second = x.second;
	}

	cout << mxx.first;

    return 0;
}
