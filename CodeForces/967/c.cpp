#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int closestLeft(int* arr, int n, int x) {
	int base = 0;
	for (int jump = n >> 1; jump; jump >>= 1) if (base + jump < n && arr[base + jump] < x) base += jump;
	return base;
}

int closestRight(int* arr, int n, int x) {
	int base = 0;
	for (int jump = n >> 1; jump; jump >>= 1) if (base + jump < n && arr[base + jump] < x) base += jump;
	return min(base + 1, n - 1);
}

int cel(int num, int denom) {
	return (num - 1) / denom + 1;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, m, cs, ce, v, q, y1, y2, x1, x2;
	scanf("%d %d %d %d %d", &n, &m, &cs, &ce, &v);
	int stairs[cs], elev[ce];
	fl (i, 0, cs) scanf("%d", &stairs[i]);
	fl (i, 0, ce) scanf("%d", &elev[i]);

	scanf("%d", &q);
	while (q--) {
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
		ll sm1 = 0, sm2 = 0, sm3 = 0, sm4 = 0;

		if (y1 == y2) {printf("%d\n", abs(x2 - x1)); continue;}

		if (cs > 0) {
			sm1 += abs(y2 - y1);
			int closeLeft1 = stairs[closestLeft(stairs, cs, x1)];
			sm1 += abs(closeLeft1 - x1) + abs(closeLeft1 - x2);
			//cout << abs(y2 - y1) << " " << abs(closeLeft1 - x1) + abs(closeLeft1 - x2) << " " << closeLeft1 << endl;

			sm2 += abs(y2 - y1);
			int closeRight1 = stairs[closestRight(stairs, cs, x1)];
			sm2 += abs(closeRight1 - x1) + abs(closeRight1 - x2);
		}
		if (ce > 0) {
			sm3 += cel(abs(y2 - y1), v);
			int closeLeft2 = elev[closestLeft(elev, ce, x1)];
			sm3 += abs(closeLeft2 - x1) + abs(closeLeft2 - x2);

			sm4 += cel(abs(y2 - y1), v);
			int closeRight2 = elev[closestRight(elev, ce, x1)];
			sm4 += abs(closeRight2 - x1) + abs(closeRight2 - x2);
		}

		printf("%lld\n", min(min(sm1 > 0 ? sm1 : 1000000000, sm2 > 0 ? sm2 : 1000000000), min(sm3 > 0 ? sm3 : 1000000000, sm4 > 0 ? sm4 : 1000000000)));
	}

	return 0;
}
