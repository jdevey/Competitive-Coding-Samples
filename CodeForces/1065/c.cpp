#include <bits/stdc++.h>

#define MX 200001ll

using namespace std;

typedef long long ll;

int main() {

	ll n, k;
	scanf("%lld %lld", &n, &k);
	ll* a = new ll[n];
	memset(a, 0, sizeof(a));
	for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);

	ll* cs = new ll[MX];
	memset(cs, 0, sizeof(cs));
	for (int i = 0; i < n; ++i) ++cs[a[i]];

	ll* ps = new ll[MX];
	memset(ps, 0, sizeof(ps));
	ps[MX - 1] = cs[MX - 1];
	for (int i = MX - 2; i > -1; --i) ps[i] = ps[i + 1] + cs[i];

	ll mn = 1e9;
	for (int i = 0; i < n; ++i) mn = min(mn, a[i]);

	ll mx = 0;
	for (int i = 0; i < n; ++i) mx = max(mx, a[i]);

	ll total = mx != mn ? 1 : 0, curr = k;
	for (int i = MX - 1; i >= mn; --i) {
		if (ps[i] > curr) {
			curr = k - ps[i];
			if (i != mn) ++total;
		}
		else {
			curr -= ps[i];
		}
	}

	printf("%lld", total);

    return 0;
}
