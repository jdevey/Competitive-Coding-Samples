#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	
	int n, k;
	cin >> n >> k;
	int a[n];
	fl (i, 0, n) cin >> a[i];

	sort(a, a + n);

	vector <int> filt;
	fl (i, 0, n) if (i == n - 1 || a[i] != a[i + 1]) filt.push_back(a[i]);

	int sz = filt.size();
	fl (i, 0, k) {
	    if (i == 0) cout << filt[0] << endl;
	    else if (i >= sz) cout << 0 << endl;
	    else cout << filt[i] - filt[i - 1] << endl;
	}
	
    return 0;
}
