#include <bits/stdc++.h>

#define fl(i,a,b) for(int(i)=(a);(i)<(b);++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	int a[n], b[n];
	fl (i, 0, n) cin >> a[i];
	fl (i, 0, n) cin >> b[i];

	int mx[n] = {};
	ll sm[n] = {};
	fl (i, 0, n) {
		mx[a[i]] = max(mx[a[i]], b[i]);
		sm[a[i]] += b[i];
	}

	ll gs = 0;
	fl (i, 0, n) gs += sm[i] - mx[i];
	cout << gs << endl;

	return 0;
}
