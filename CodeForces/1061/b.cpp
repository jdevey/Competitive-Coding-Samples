#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {

	int n, m;
	cin >> n >> m;
	int a[n];
	fl (i, 0, n) cin >> a[i];

	sort(a, a + n);

	int pt = 0;

	fl (i, 0, n - 1) {
		if (a[i] > pt || a[i] > a[i - 1]) {
			++pt;
		}
	}

	ll sm = 0;
	fl (i, 0, n) sm += a[i];

	cout << sm - (n - 1 + max(a[n - 1] - pt, 1)) << endl;

    return 0;
}
