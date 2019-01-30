#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ll w, h, k;

	cin >> w >> h >> k;

	ll sm = 0;
	for (int i = 0; i < k; ++i) {
		sm += (w - 4 * i) * 2 + ((h - 4 * i) - 2) * 2;
	}

	cout << sm << endl;

    return 0;
}
