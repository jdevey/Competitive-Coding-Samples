#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, k;
	cin >> n >> k;

	if (n == k || !k) {
		cout << 0 << " " << 0 << endl;
		return 0;
	}
	else {
		cout << 1 << " ";
		int m = n / 3;
		if (k <= m) cout << 2 * k;
		else cout << 2 * m - (k - m) + n % 3;
	}

    return 0;
}
