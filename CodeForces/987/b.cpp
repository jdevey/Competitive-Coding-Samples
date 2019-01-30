#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ll x, y;
	cin >> x >> y;
	if (x == y || x == 2 && y == 4 || y == 2 && x == 4) return puts("=");
	if (x == 1) return puts("<");
	if (y == 1) return puts(">");
	if (x == 2 && y == 3) return puts("<");
	if (y == 2 && x == 3) return puts(">");
	if (x < y) return puts(">");
	else return puts("<");

    return 0;
}
