#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int main() {

	int t;
	cin >> t;
	for (int tt = 1; tt <= t; ++tt) {
		cout << "Recipe # " << tt << endl;
		int n, p, d;
		cin >> n >> p >> d;
		ld ratio = (ld)d / p;
		vector <pair<string, pair <ld, ld>>> m;
		string base;
		ld bw;
		for (int i = 0; i < n; ++i) {
			string s;
			ld l1, l2;
			cin >> s >> l1 >> l2;
			m.push_back({s, {l1, l2}});
			if (l2 == 100.0) {base = s; bw = ratio * l1;}
		}
		cout.precision(1);
		for (vector <pair<string, pair <ld, ld>>>::iterator it = m.begin(); it != m.end(); ++it) {
			if (it->first == base) {
				cout << it->first << " " << fixed << ratio * it->second.first << endl;
			}
			else {
				cout << it->first << " " << fixed << bw * it->second.second / 100 << endl;
			}
		}
		for (int i = 0; i < 40; ++i) cout << "-";
		cout << endl;
	}

	return 0;
}
