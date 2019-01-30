#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int main() {

	int n, t;
	cin >> n >> t;
	ld polys[n][3];

	for (int i = 0; i < n; ++i) {
		ld a, b, c;
		cin >> a >> b >> c;
		polys[i][0] = a;
		polys[i][1] = b;
		polys[i][2] = c;
	}

	ld delta = 0.00001;

	ld vals[n];
	for (int i = 0; i < n; ++i) vals[i] = 0;

	for (ld sm = 0; sm < t; sm += delta) {
		ld bestinc = 0;
		int bestind = 0;
		for (int i = 0; i < n; ++i) {
			ld inc = (polys[i][0] * (vals[i] + delta) * (vals[i] + delta) + polys[i][1] * (vals[i] + delta)) - (polys[i][0] * vals[i] * vals[i] + polys[i][1] * vals[i]);
			if (inc > bestinc) {
				bestinc = inc;
				bestind = i;
			}
		}
		vals[bestind] += delta;
	}

	ld sm = 0;
	for (int i = 0; i < n; ++i) {
		sm += polys[i][0] * vals[i] * vals[i] + polys[i][1] * vals[i] + polys[i][2];
	}

	cout.precision(10);
	cout << fixed << sm / n << endl;

	return 0;
}
