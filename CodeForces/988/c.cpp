#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, ni, ai;
	cin >> n;
	vector <vector <int>> grid;
	fl (i, 0, n) {
		cin >> ni;
		grid.push_back(vector <int>());
		fl (j, 0, ni) {
			cin >> ai;
			grid[i].push_back(ai);
		}
	}

	int pss[n] = {};
	fl (i, 0, n) fl (j, 0, grid[i].size()) pss[i] += grid[i][j];

	map <int, pair <int, int>> m;
	fl (i, 0, n) fl (j, 0, grid[i].size()) {
		if (m.find(pss[i] - grid[i][j]) != m.end() && m.find(pss[i] - grid[i][j])->second.first != i) {
			cout << "YES" << endl;
			cout << i + 1 << " " << j + 1 << endl;
			auto it = m.find(pss[i] - grid[i][j]);
			cout << it->second.first + 1 << " " << it->second.second + 1 << endl;
			return 0;
		}
		else m[pss[i] - grid[i][j]] = make_pair(i, j);
	}

	cout << "NO" << endl;

    return 0;
}
