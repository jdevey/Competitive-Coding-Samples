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

	int s = 0;
	fl (i, 0, n) s += abs(a[i]);

	cout << s;

    return 0;
}
