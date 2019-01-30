#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

ld quad(ll n) {
	return (n + sqrt(n * n - 4 * n)) / 2;
}

int main() {

	ll q;
	cin >> q;
	cout.precision(12);
	cout << fixed;
	while (q--) {
		ld n;
		cin >> n;
		if (n == 0) {
			cout << "Y 0 0\n";
			continue;
		}
		if (n < 4) {
			cout << "N\n";
			continue;
		}
		cout << "Y " << quad(n) << " " << n - quad(n) << endl;
	}

    return 0;
}
