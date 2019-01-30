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

	if (n == 1) return puts("1");
	if (n & 1) {
		if (m == n / 2 + 1) cout << n / 2;
		else if (m < n / 2 + 1) cout << m + 1;
		else cout << m - 1;
	}
	else {
		if (m < n / 2 + 1) cout << m + 1;
		else cout << m - 1;
	}

    return 0;
}
