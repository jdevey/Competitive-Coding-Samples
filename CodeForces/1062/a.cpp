#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {

	int n;
	cin >> n;
	int a[n];
	fl (i, 0, n) cin >> a[i];

	int mx = 0, cnt = 0;

	fl (i, 0, n) {
		if (((i == 0 && a[i] == 1) || a[i - 1] == a[i] - 1) && ((i == n - 1 && a[i] == 1000) || a[i + 1] == a[i] + 1)) ++cnt;
		else {
			mx = max(mx, cnt);
			cnt = 0;
		}
	}
	mx = max(mx, cnt);

	cout << mx << endl;

    return 0;
}
