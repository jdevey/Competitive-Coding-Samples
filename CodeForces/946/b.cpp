#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

	#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
	#endif

	ll a, b;
	cin >> a >> b;

	while (true) {
		if (!a || !b) break;
		if (a >= 2 * b) a %= 2 * b;
		else if (b >= 2 * a) b %= 2 * a;
		else break;
	}

	cout << a << " " << b << endl;

    return 0;
}

