/*
ID: deveyjo1
TASK: castle
LANG: C++14            
*/
#include <bits/stdc++.h>

using namespace std;

struct Node {
	int adj, id;
	int& space;
	explicit Node(int _adj) {
		adj = _adj;
	}
};

void dfs(vector <vector <Node*>>& a, vector <vector <bool>>& vis, int& space, int id, int y, int x, int& n, int& m, int& mxRm) {
	vis[y][x] = true;
	++space;
	a[y][x].space = space;
	a[y][x].id = id;
	mxRm = max(mxRm, space);
	if (x > 0 	  && !vis[y][x - 1] && a[y][x].adj & 1 << 0) dfs(a, vis, space, id, y, x - 1, n, m, mxRm);
	if (y > 0 	  && !vis[y - 1][x] && a[y][x].adj & 1 << 1) dfs(a, vis, space, id, y - 1, x, n, m, mxRm);
	if (x < m - 1 && !vis[y][x + 1] && a[y][x].adj & 1 << 2) dfs(a, vis, space, id, y, x + 1, n, m, mxRm);
	if (y < n - 1 && !vis[y + 1][x] && a[y][x].adj & 1 << 3) dfs(a, vis, space, id, y + 1, x, n, m, mxRm);
}

void printGrid(vector <vector <Node*>>& a) {
	for (auto x : a) {
		for (auto y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
}

int main() {
    
	freopen("castle.in", "r", stdin);
	//freopen("castle.out", "w+", stdout);

	int n, m;
	cin >> m >> n;
	vector <vector <Node*>> a(n, vector <Node*>);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int adj;
			cin >> adj;
			a[i].push_back(new Node(adj));
		}
	}

	vector <int> spaces;
	vector <vector <bool>> vis(n, vector <bool>(m, 0));
	register int mxRm = 0;

	for (int i = 0; i < n; ++I) {
		for (int j = 0; j < m; ++j) {
			if (!vis[i][j]) {
				spaces.push_back(0);
				dfs(a, vis, spaces.back(), spaces.size(), i, j, n, m, mxRm);
			}
		}
	}

	cout << spaces.size() << endl << mxRm << endl;

	

    return 0;
}
