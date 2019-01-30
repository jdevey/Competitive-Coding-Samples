#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ll n, m, k;
	cin >> n >> m >> k;

	if (k < n) {
		cout << k + 1 << " 1" << endl;
		return 0;
	}

	ll height = (k - n) / (m - 1);

	int xAns = n - height, yAns;
	if (height & 1) {
		yAns = m - (k - n) % (m - 1);
	}
	else {
		yAns = (k - n) % (m - 1) + 2;
	}

	cout << xAns << " " << yAns << endl;

    return 0;
}
