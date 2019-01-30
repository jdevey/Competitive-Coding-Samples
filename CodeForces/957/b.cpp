#include <bits/stdc++.h>

#define F first
#define S second
#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

bool isTrio(int ay, int ax, int by, int bx, int cy, int cx) {
	return ay == by && ax == cx || ay == cy && ax == bx || by == ay && bx == cx || by == cy && bx == ax || cy == ay && cx == bx || cy == by && cx == ax;
}

pair <int, int> findEx(int ay, int ax, int by, int bx, int cy, int cx) {
	if (ay == by && ax == cx) {
		return {cy, bx};
	}
	else if (ay == cy && ax == bx) {
		return {by, cx};
	}
	else if (by == ay && bx == cx) {
		return {cy, ax};
	}
	else if (by == cy && bx == ax) {
		return {ay, cx};
	}
	else if (cy == ay && cx == bx) {
		return {by, ax};
	}
	else if (cy == by && cx == ax) {
		return {ay, bx};
	}
}

bool exists(vector <pair <int, int>>& m, int x, int y) {
	fl (i, 0, m.size()) if (m[i].first == y && m[i].second == x) return true;
	return false;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, mm;
	cin >> n >> mm;
	string grid[n];
	fl (i, 0, n) cin >> grid[i];

	vector <pair <int, int>> vp;
	set <pair <int, int>> m;

	fl (i, 0, n) fl (j, 0, mm) if (grid[i][j] == '#') m.insert({i, j});
	fl (i, 0, n) fl (j, 0, mm) if (grid[i][j] == '#') vp.push_back({i, j});
	int sz = vp.size();

	fl (i, 0, sz) fl (j, 0, sz) {
		if (vp[i].F == vp[j].F || vp[i].S == vp[j].S) continue;
		int cnt = 0;
		if (m.find({vp[i].F, vp[j].S}) != m.end()) ++cnt;
		if (m.find({vp[j].F, vp[i].S}) != m.end()) ++cnt;
		//cout << vp[i].F << " " << vp[i].S << " " << vp[j].F << " " << vp[j].S << endl;
		//cout << i << " " << j << " " << cnt << endl;
		if (cnt & 1) {
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;

	return 0;
}
