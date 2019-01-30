#include <bits/stdc++.h>

#define MAX 0x3fffffffffffffffll

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef unsigned long long ull;

ull findUpperTri(ull n) {
	ull base = 0;
	for (ull jump = MAX; jump; jump >>= 1) while ((base + jump) * (base + jump + 1) < 2 * n) base += jump;
	return base + 1;
}

ull compSand(ull x, ull h) {
	x += h;
	return x * (x + 1) / 2 - h * (h + 1) / 2;
}

ull BS(ull n, ull h) {
	ull base = 0;
	for (ull jump = MAX; jump; jump >>= 1) while (compSand(base + jump, h) < n) base += jump;
	return base + 1;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ull n, h;
	cin >> n >> h;

	if (h * (h + 1) / 2 >= n) {
		cout << findUpperTri(n) << endl;
		return 0;
	}

	n -= h * (h + 1) / 2;
	ull startWidth = h + 1;

	cout << BS(n, h) + h << endl;

    return 0;
}
