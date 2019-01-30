#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll n, k, mx = 0, a[100000];
	map <ll, ll> m;
	cin >> n >> k;
	for (ll i = 0; i < n; ++i) cin >> a[i];
	for (ll i = 0; i < n; ++i) ++m[a[i] - k * i];
	for (auto x : m) mx = max(mx, x.second);
	cout << n - mx << endl;
	return 0;
}
