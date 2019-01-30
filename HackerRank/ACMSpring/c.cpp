#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int l3(int n) {
	int b = 1, cnt = 0;
	while (b < n) {
		b *= 3;
		++cnt;
	}
	return cnt;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int t, n;
	cin >> t;

	while (t--) {
		cin >> n;
		cout << l3(n) << endl;
	}

    return 0;
}
