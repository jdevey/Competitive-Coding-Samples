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
	int a[n];
	fl (i, 0, n) cin >> a[i];

	int mx = 1, ind = 0;
	fl (i, 1, n) {
		if (a[i] > a[i - 1]) {
			mx = max(mx, i - ind + 1);
		}
		else {
			ind = i;
		}
	}

	cout << mx;

    return 0;
}
