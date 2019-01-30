#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, a, b, c, t;
	cin >> n >> a >> b >> c >> t;
	int aa[n];
	fl (i, 0, n) cin >> aa[i];

	int s = n * 5;
	int prefSum = 0;
	fl (i, 0, n) prefSum += aa[i] - 1;

	if (b < c) {
		cout << s + (c - b) * prefSum;
	}
	else {
		
	}

    return 0;
}
