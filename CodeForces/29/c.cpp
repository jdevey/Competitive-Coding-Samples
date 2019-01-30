#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n;
	cin >> n;

	map <int, vector <int>> mv;

	fl (i, 0, n) {
		int a1, a2;
		cin >> a1 >> a2;
		mv[a1].push_back(a2);
		mv[a2].push_back(a1);
	}

	int start;

	for (auto x : mv) {
		if (x.second.size() == 1) {
			start = x.first;
			break;
		}
	}

	set <int> vis;
	bool isFirst = true;

	while (true) {
		cout << start << " ";
		if (mv[start].size() == 1 && !isFirst) break;
		isFirst = false;
		for (auto x : mv[start]) {
			if (vis.find(x) == vis.end()) {
				vis.insert(start);
				start = x;
			}
		}
	}

    return 0;
}
