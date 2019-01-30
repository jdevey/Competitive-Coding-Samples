#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

ll cel(ll a, ll b) {
	return (a - 1) / b + 1;
}

int main() {

	ll n, k;
	cin >> n >> k;

	cout << cel(n * 2, k) + cel(n * 5, k) + cel(n * 8, k) << endl;

    return 0;
}
