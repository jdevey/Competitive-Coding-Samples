#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ll t, L, v, l, r;
	cin >> t;
	while (t--) {
		cin >> L >> v >> l >> r;
		cout << L / v - r / v + (l - 1) / v << endl;
	}

    return 0;
}
