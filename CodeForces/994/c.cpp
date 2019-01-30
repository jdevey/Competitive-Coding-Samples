#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

bool inSquare(int* a, int ptx, int pty) {
	return ptx <= a[0] ^ ptx <= a[4] | ptx >= a[0] ^ ptx >= a[4] && pty <= a[1] ^ pty <= a[5] | pty >= a[1] ^ pty >= a[5];
}

bool inTilted(int* b, int ptx, int pty) {
	int diam = abs(b[0] - b[4]) + abs(b[1] - b[5]);
	int bx, by = 100;
	for (int i = 1; i < 8; i += 2) {
		if (b[i] < by) {
			by = b[i];
			bx = b[i - 1];
		}
	}
	return pty - ptx <= by - bx ^ pty - ptx <= by - bx + diam | pty - ptx >= by - bx ^ pty - ptx >= by - bx + diam &&
		pty + ptx <= by + bx ^ pty + ptx <= by + bx + diam | pty + ptx >= by + bx ^ pty + ptx >= by + bx + diam;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int a[8], b[8];
	fl (i, 0, 8) cin >> a[i];
	fl (i, 0, 8) cin >> b[i];

	for (int i = -100; i <= 100; ++i) {
		for (int j = -100; j <= 100; ++j) {
			if (inSquare(a, i, j) & inTilted(b, i, j)) return puts("YES");
		}
	}

	cout << "NO";

    return 0;
}
