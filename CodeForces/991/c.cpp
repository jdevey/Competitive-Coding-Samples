#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

bool isGood(ll n, ll k) {
	if (k == 0) return true;
	ll origN = n, cnt = 0;
	while (n > 0) {
		cnt += min(k, n);
		n -= k;
		n -= n / 10;
	}
	return cnt >= (origN + 1) / 2;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ll n;
	cin >> n;
	ll base = n / 100;
	for (ll jump = 1000000000000000000LL; jump; jump /= 2) while (!isGood(n, base + jump)) base += jump;
	cout << base + 1 << endl;

    return 0;
}
