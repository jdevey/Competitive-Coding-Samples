#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {

	int n, m, l;
	cin >> n >> m >> l;
	ll a[n];
	fl (i, 0, n) cin >> a[i];

	int total = 0;
	fl (i, 0, n) {
		if (a[i] > l && (i == 0 || a[i - 1] <= l)) ++total;
	}

	while (m--) {
		int type;
		cin >> type;
		if (!type) cout << total << endl;
		else {
			int pos, val;
			cin >> pos >> val;
			--pos;
			if (a[pos] <= l && a[pos] + val > l) {
				//cout << pos << "!\n";
				if ((pos == 0 || a[pos - 1] <= l) && (pos == n - 1 || a[pos + 1] <= l)) ++total;
				else if (pos > 0 && pos < n - 1 && a[pos - 1] > l && a[pos + 1] > l) --total;
			}
			a[pos] += val;
		}
	}

	return 0;
}

