#include "bits/stdc++.h"

#define D 0.00001

using namespace std;

typedef long long ll;
typedef long double ld;

void printVec(vector <ld>& v) {
	for (auto x : v) cout << x << " ";
	cout << endl;
}

vector <ld> position(ld* pos, ld* v, ld t) {
	vector <ld> ret = {pos[0] + v[0] * t, pos[1] + v[1] * t, pos[2] + v[2] * t};
	return ret;
}

ld d(ld* pos1, ld* pos2, ld* v1, ld* v2, ld t) {
	vector <ld> p1 = position(pos1, v1, t), p2 = position(pos2, v2, t);
	//printVec(p1);
	//printVec(p2);
	return sqrt(pow(p2[0] - p1[0], 2) + pow(p2[1] - p1[1], 2) + pow(p2[2] - p1[2], 2));
}

ld dddt(ld* pos1, ld* pos2, ld* v1, ld* v2, ld t) {
	//cout << d(pos1, pos2, r1, r2, v1, v2, t + D) << " " << d(pos1, pos2, r1, r2, v1, v2, t) << endl;
	return (d(pos1, pos2, v1, v2, t + D) - d(pos1, pos2, v1, v2, t)) / D;
}

ld bs1(ld* pos1, ld* pos2, ld* v1, ld* v2) {
	ld base = 0;
	//cout << "derivative " << dddt(pos1, pos2, r1, r2, v1, v2, 2.1) << endl;
	for (ld jump = 1e6; jump > 1e-6; jump /= 2) while (dddt(pos1, pos2, v1, v2, base + jump) < 0) base += jump;
	return base;
}

ld bs2(ld* pos1, ld* pos2, ld r1, ld r2, ld* v1, ld* v2, ld upLim) {
	ld base = upLim;
	for (ld jump = 1e6; jump > 1e-6; jump /= 2) while (d(pos1, pos2, v1, v2, base - jump) <= r1 + r2) base -= jump;
	return base;
}

int main() {
	cout.precision(3);
	cout << fixed;
	int t;
	cin >> t;
	while (t--) {
		ld pos1[3], pos2[3], r1, r2, v1[3], v2[3];
		cin >> pos1[0] >> pos1[1] >> pos1[2] >> r1 >> v1[0] >> v1[1] >> v1[2];
		cin >> pos2[0] >> pos2[1] >> pos2[2] >> r2 >> v2[0] >> v2[1] >> v2[2];
		if (v1[0] == v2[0] && v1[1] == v2[1] && v1[2] == v2[2]) {
			cout << "No collision\n";
			continue;
		}
		ld closePos = bs1(pos1, pos2, v1, v2);
		//cout << closePos << endl;
		if (d(pos1, pos2, v1, v2, closePos) >= r1 + r2) {
			cout << "No collision\n";
			continue;
		}
		cout << round(bs2(pos1, pos2, r1, r2, v1, v2, closePos) * 1000) / 1000 << endl;
	}

	return 0;
}
