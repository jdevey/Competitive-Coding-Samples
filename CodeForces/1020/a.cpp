#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {

	ll n, h, a, b, k;
	cin >> n >> h >> a >> b >> k;

	while (k--) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ll total = abs(x2 - x1);
		if (x1 != x2 && y1 < a && y2 < a) total += a - y1 + a - y2;
		else if (x1 != x2 && y1 > b && y2 > b) total += y1 - b + y2 - b;
		else total += abs(y2 - y1);
		cout << total << endl;
	}

    return 0;
}
