#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

pair <pair <int, int>, pair <int, int>> minSeg(vector <int>& v1, int s1, vector <int>& v2, int s2) {
	int minSize = 1e9, ind1 = 0, ind2 = 0, i1 = 0, i2 = 0;
	while (true) {
		int p11 = v1[i1], p12 = v1[i1 + s1 - 1];
		int p21 = v2[i2], p22 = v2[i2 + s2 - 1];
		int sz = max(p12, p22) - min(p11, p21) + 1;
		if (sz < minSize) {
			ind1 = i1;
			ind2 = i2;
			minSize = sz;
		}
		if (p11 < p21) {
			if (i1 + s1 == v1.size() - 1) break;
			++i1;
		}
		if (p12 < p22) {
			if (i2 + s2 == v2.size() - 1) break;
			++i2;
		}
	}
	return make_pair(make_pair(v1[ind1], v2[ind2]), make_pair(v1[ind1 + s1 - 1], v2[ind2 + s2 - 1]));
}

pair <int, int> ms(vector <int>& v, int s) {
	cout << s << endl;
	int minSize = 1e9, ind = 0;
	for (int i = 0; i < v.size() - s + 1; ++i) {
		int p1 = v[i];
		int p2 = v[i + s - 1];
		int sz = p2 - p1 + 1;
		if (sz < minSize) {
			minSize = sz;
			ind = i;
		}
	}
	return make_pair(v[ind], v[ind + s - 1]);
}

int main() {

	int n;
	cin >> n;
	string s;
	cin >> s;
	int x, y;
	cin >> x >> y;

	if (abs(x) + abs(y) > n) return puts("-1");

	vector <int> px, nx, py, ny;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'L') nx.push_back(i);
		if (s[i] == 'R') px.push_back(i);
		if (s[i] == 'D') ny.push_back(i);
		if (s[i] == 'U') py.push_back(i);
	}

	int xg = x - (px.size() - nx.size()), yg = y - (py.size() - ny.size());

	if (xg == 0 && yg == 0) return puts("0");
	if (xg == 0) {
		auto p = ms(yg > 0 ? ny : py, abs(yg));
		cout << p.second - p.first + 1 << endl;
		return 0;
	}
	if (yg == 0) {
		auto p = ms(xg > 0 ? nx : px, abs(xg));
		cout << p.second - p.first + 1 << endl;
		return 0;
	}

	pair <pair <int, int>, pair <int, int>> pp;
	pp = minSeg(xg > 0 ? nx : px, abs(xg), yg > 0 ? ny : py, abs(yg));

	cout << max(pp.first.first, pp.first.second) - min(pp.second.first, pp.second.second) + 1 << endl;

    return 0;
}
