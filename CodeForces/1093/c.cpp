#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {

	ll n;
	cin >> n;
	ll b[n / 2];
	fl (i, 0, n / 2) cin >> b[i];

	ll a[n];
	a[0] = 0;
	a[n - 1] = b[0];

	fl (i, 1, n / 2) {
		ll mn = a[i - 1];
		ll mx = a[n - i];
		ll mxDiff = max(b[i] - mx, mn);
		a[i] = mxDiff;
		a[n - i - 1] = b[i] - mxDiff;
	}

	fl (i, 0, n) cout << a[i] << " ";
	cout << endl;

    return 0;
}
