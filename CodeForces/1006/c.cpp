#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];

	ll ps[n];
	ps[0] = a[0];
	for (int i = 1; i < n; ++i) ps[i] = ps[i - 1] + a[i];

	ll total = 0;

	int pt1 = 0, pt2 = n;

	while (pt1 <= pt2) {
		ll s1 = pt1 == 0 ? 0 : ps[pt1 - 1];
		ll s2 = pt2 == n ? 0 : ps[n - 1] - (pt2 == 0 ? 0 : ps[pt2 - 1]);
		if (s1 == s2) {total = max(total, s1); ++pt1;}
		else if (s1 > s2) --pt2;
		else ++pt1;
	}

	cout << total << endl;

    return 0;
}
