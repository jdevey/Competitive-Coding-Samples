#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ll n, m, room;
	cin >> n >> m;
	ll a[n];
	fl (i, 0, n) cin >> a[i];

	ll ps[n];
	ps[0] = 0;
	fl (i, 1, n) ps[i] = ps[i - 1] + a[i - 1];

	while (m--) {
		cin >> room;
		int ind = lower_bound(ps, ps + n, room) - ps - 1;
		ll rm = room - ps[ind];
		cout << ind + 1 << " " << rm << endl;
	}

    return 0;
}
