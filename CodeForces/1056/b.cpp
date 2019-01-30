#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	
	ll n, m;
	cin >> n >> m;

	ll ans = 0;

	fl (i, 1, m + 1) {
		fl (j, 1, m + 1) {
			if ((i * i + j * j) % m == 0) {
				ll a = n / m + (i % m && i % m <= n % m);
				ll b = n / m + (j % m && j % m <= n % m);
				ans += a * b;
			}
		}
	}

	cout << ans << endl;
	
    return 0;
}
