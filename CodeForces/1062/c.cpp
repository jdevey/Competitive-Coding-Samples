#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))
#define MD 1000000007ll

using namespace std;

typedef long long ll;
typedef long double ld;

ll pw(ll base, ll exp) {
	return exp ? ((exp & 1 ? base : 1ll) * pw(base * base % MD, exp >> 1) % MD) : 1ll;
}

int main() {

	//printf("%lld\n", pw(3, 4));

	ll n, q;
	scanf("%lld %lld", &n, &q);
	//cin >> n >> q;
	//cout << n << " " << q << endl;

	char a[200000];
	scanf("%s", &a);
	//string a;
	//cin >> a;
	//cout << a << endl;

	ll ps[n];
	ps[0] = a[0] == '1';
	fl (i, 1, n) ps[i] = ps[i - 1] + (a[i] == '1');

	while (q--) {
		ll l, r;
		//cin >> l >> r;
		scanf("%lld %lld", &l, &r);
		//cout << l << " " << r << endl;
		--l; --r;
		ll no = ps[r] - (l ? ps[l - 1] : 0);
		ll nz = (r - l + 1) - no;
		//cout << no << " " << nz << "!" << endl;
		ll ans = pw(2, no) - 1;
		ans += ans * (pw(2, nz) - 1);
		ans %= MD;
		printf("%lld\n", ans);
	}

    return 0;
}
