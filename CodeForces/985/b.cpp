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

	//fl (i, 0, n) cout << a[i] << endl;

	//cout << endl;

	int vcs[m] = {}, hcs[n] = {};
	fl (i, 0, n) fl (j, 0, m) {
		if (a[i][j] == '1') {
			++vcs[j];
			++hcs[i];
		}
	}

	fl (i, 0, n) {
		int unnecc = 0;
		fl (j, 0, m) {
			if (a[i][j] == '1' && vcs[j] > 1) ++unnecc;
		}
		if (unnecc == hcs[i]) {
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "NO" << endl;
    return 0;
}
