#include <bits/stdc++.h>

#define MD 1000000007LL
//#define MD 13
#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

ll power(ll base, ll exp) {
	ll ans = 1;
	while (exp) {
		if (exp & 1) ans = ans * base % MD;
		exp >>= 1;
		base = base * base % MD;
	}
	return ans;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ll n, k;
	cin >> n >> k;

	if (n == 0) return puts("0");

	n = n * 2 - 1;
	n %= MD;

	n = n % MD * power(2, k) + 1;

	cout << n % MD << endl;

    return 0;
}
