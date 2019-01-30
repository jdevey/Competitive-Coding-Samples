#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

#define PI 3.14159256385l

using namespace std;

typedef long long ll;
typedef long double ld;

pair <ld, ld> findCenter(ld x1, ld x2, ld x3, ld y1, ld y2, ld y3) {
	ld xc, yc;

	ld dx1 = x1 - x2;
	ld dy1 = y1 - y2;
	ld dx2 = x2 - x3;
	ld dy2 = y2 - y3;






	xc = ((x1 * x1 + y1 * y1) * (y2 - y3) + (x2 * x2 + y2 * y2) * (y3 - y1) + (x3 * x3 + y3 * y3) * (y1 - y2)) / d;
	yc = ((x1 * x1 + y1 * y1) * (x3 - x2) + (x2 * x2 + y2 * y2) * (x1 - x3) + (x3 * x3 + y3 * y3) * (x2 - x1)) / d;
	return {xc, yc};
}

ld calcRad(ld xc, ld yc, ld px, ld py) {
	return sqrt((px - xc) * (px - xc) + (py - yc) * (py - yc));
}

bool isValid(ld x1, ld x2, ld x3, ld y1, ld y2, ld y3, ld rad, pair <ld, ld> ct, int side) {
	int cnt = 1;
	ld angle = arctan(y1, x1);
	for (int i = 1; i < size; ++i) {
		angle = angle + 2 * PI - (angle + 2 * PI > 2 * PI ? 2 * PI : 0);
		ld npx = cos(angle) * rad, npy = sin(angle) * rad;
		if (abs(npx - x2) < 1e7 && abs(npy - y2) < 1e7 || abs(npx - x3) < 1e7 && abs(npy - y3)) {
			++cnt;
		}
	}
	return cnt == side;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ld x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	pair <ld, ld> ct = findCenter(x1, x2, x3, y1, y2, y3);

	ld rad = calcRad(ct.first, ct.second, x1, y1);

	for (int i = 3; i <= 100; ++i) {
		if (isValid(x1, x2, x3, y1, y2, y3, rad, ct, i)) {
			ld ans;
			ld npx = cos(PI / i) * rad, npy = sin(PI / i) * rad;
			ans = npx * npy * i;
			cout << ans;
			return 0;
		}
	}

    return 0;
}
