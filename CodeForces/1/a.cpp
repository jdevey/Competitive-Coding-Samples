#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

ll cel(ll a, ll b) {
	return (a - 1) / b + 1;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ll n, m, a;
	cin >> n >> m >> a;

	cout << cel(n, a) * cel (m, a);

    return 0;
}
