#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ll d, k, a, b, t;
	cin >> d >> k >> a >> b >> t;

	ll mn = 1ll << 63 - 1;

	if (k >= d) {
		cout << d * a << endl;
		return 0;
	}

	ll s1 = 0;
	s1 = k * a;
	s1 += (d - k) * b;
	mn = min(mn, s1);

	ll s2 = 0;
	ll left = d / k;
	s2 += left * (k * a + t) - t;
	s2 += d % k * b;
	mn = min(mn, s2);

	ll s3 = 0;
	ll lefty = d / k + 1;
	s3 += (lefty - 1) * (k * a + t);
	s3 += d % k * a;
	mn = min(mn, s3);

	cout << mn << endl;

    return 0;
}
