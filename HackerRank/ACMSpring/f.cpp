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
	int a[n], b[m];
	fl (i, 0, n) cin >> a[i];
	fl (j, 0, m) cin >> b[j];

	int pt1 = 0, pt2 = 0;
	int minDiff = min(minDiff, abs(a[0] - b[0]));

	while (!(pt1 == n - 1 && pt2 == m - 1)) {
		if (pt1 == n - 1) ++pt2;
		else if (pt2 == m - 1) ++pt1;
		else if (a[pt1] > b[pt2]) ++pt2;
		else ++pt1;
		minDiff = min(minDiff, abs(a[pt1] - b[pt2]));
	}

	cout << minDiff << endl;

    return 0;
}
