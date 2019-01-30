#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ll n, m, a;
	cin >> n >> m;
	ll c = 0;
	fl (i, 0, n) {
		cin >> a;
		c += a;
		cout << c / m << " ";
		c %= m;
	}

    return 0;
}
