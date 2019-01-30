#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	int a[n];
	fl (i, 0, n) cin >> a[i];
	sort(a, a + n);
	int sm = 0, target = (n * 9 + 1)/ 2, cnt = 0, ii = 0;
	fl (i, 0, n) sm += a[i];
	while (sm < target) {
		sm += 5 - a[ii];
		++cnt;
		++ii;
	}

	cout << cnt << endl;

    return 0;
}
