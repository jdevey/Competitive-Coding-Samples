#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {

	int a, b, c;
	cin >> a >> b >> c;
	int mx = 6;

	if (b >= a + 1 && c >= a + 2) mx = max(mx, 3 * a + 3);
	if (a >= b - 1 && c >= b + 1) mx = max(mx, 3 * b);
	if (a >= c - 2 && b >= c - 1) mx = max(mx, 3 * c - 3);

	cout << mx << endl;

    return 0;
}
