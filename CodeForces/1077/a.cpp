#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {

	int t;
	cin >> t;
	while (t--) {
		ll a, b, k;
		cin >> a >> b >> k;
		cout << (k + 1) / 2 * a - k / 2 * b << endl;
	}

    return 0;
}
