#include <bits/stdc++.h>

#define S 0.0001

using namespace std;

typedef long double ld;

ld x[3], y[3], vx, vy, r;

ld d(int p1, int p2, ld vvx, ld vvy, ld t) {
    return sqrt(pow(x[p1] + vvx * t - x[p2], 2) + pow(y[p1] + vvy * t - y[p2], 2));
}

ld dddt(int p1, int p2, ld vvx, ld vvy, ld t) {
    return (d(p1, p2, vvx, vvy, t + S) - d(p1, p2, vvx, vvy, t)) / S;
}

ld bs(int p1, int p2, ld vvx, ld vvy) {
    ld base = 0;
    for (ld jump = 1e6; jump > 1e-6; jump /= 2) if (dddt(p1, p2, vvx, vvy, base + jump) < 0) base += jump;
    return base;
}

ld bs2(int p1, int p2, ld vvx, ld vvy, ld start) {
    ld base = start;
    for (ld jump = 100.0; jump > 1e-6; jump /= 2) if (d(p1, p2, vvx, vvy, base - jump) < 2 * r) base -= jump;
    return base;
}

int main() {

    for (int i = 0; i < 3; ++i) cin >> x[i] >> y[i];
    cin >> vx >> vy >> r;

    ld t1 = bs(0, 1, vx, vy);
    ld t2 = bs(0, 2, vx, vy);

    ld dst1 = d(0, 1, vx, vy, t1);
    ld dst2 = d(0, 2, vx, vy, t2);

    bool m1 = dst1 > 2 * r, m2 = dst2 > 2 * r;

    if (m1 & m2) {
		cout << "5\n";
		return 0;
	}

    ld contact1 = -1.0, contact2 = -1.0;
    if (!m1) contact1 = bs2(0, 1, vx, vy, t1);
    if (!m2) contact2 = bs2(0, 2, vx, vy, t2);

    bool use1;
    if (!m1 & m2) use1 = true;
    else if (m1 & !m2) use1 = false;
    else use1 = contact1 < contact2;

    ld ct = use1 ? contact1 : contact2;
    int cc = use1 ? 1 : 2;
    int ccc = use1 ? 2 : 1;
    ld cvx = x[cc] - (x[0] + vx * ct);
    ld cvy = y[cc] - (y[0] + vy * ct);

    ld ttt = bs(cc, ccc, cvx, cvy);

    ld cd = d(cc, ccc, cvx, cvy, ttt);

    bool hit = cd < 2 * r;

    cout << (hit ? use1 ? "1" : "2" : use1 ? "3" : "4") << endl;

    return 0;
}
