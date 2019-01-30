#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ll n;
	cin >> n;
	if (n == 0) {
		cout << 0;
	}
	else if (n & 1) {
		cout << (n + 1) / 2;
	}
	else {
		cout << n + 1;
	}

    return 0;
}
