#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int fs(int* a, int n, int k) {
	int sm = 0;
	for (int i = 0; i < n; ++i) sm += k - a[i];
	return sm;
}

int main() {

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];

	int mx = 0;
	for (int i = 0; i < n; ++i) mx = max(mx, a[i]);

	int sm = accumulate(a, a + n, 0);

	for (int i = mx;; ++i) {
		int s = fs(a, n, i);
		if (s > sm) {
			cout << i << endl;
			return 0;
		}
	}

	return 0;
}
