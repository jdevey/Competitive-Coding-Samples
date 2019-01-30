#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll tri(ll n) {
	return n * (n - 1) / 2;
}

int main() {

	ll n, m;
	cin >> n >> m;

	cout << max(n - 2 * m, 0ll) << " ";

	ll base = 0;
	while (tri(base) < m) ++base;

	cout << n - base << endl;

    return 0;
}
