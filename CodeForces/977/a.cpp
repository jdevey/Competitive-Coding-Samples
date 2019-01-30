#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, k;
	cin >> n >> k;

	while (k--) {
		if (n % 10 == 0) {
			n /= 10;
		}
		else --n;
	}

	cout << n;

    return 0;
}
