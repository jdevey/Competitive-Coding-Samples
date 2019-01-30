#include <bits/stdc++.h>

using namespace std;

void dfs(vector <int>* adj, int* seq, int* pos, int* nc, int ind, int& i) {
	seq[i] = ind;
	pos[ind] = i;
	int f = i;
	for (auto x : adj[ind]) {
		++i;
		dfs(adj, seq, pos, nc, x, i);
	}
	nc[ind] = i - f;
}

int main() {

	int n, q;
	scanf("%d %d", &n, &q);

	vector <int> adj[n + 1];
	for (int i = 2; i <= n; ++i) {
		int p;
		scanf("%d", &p);
		adj[p].push_back(i);
	}

	for (int i = 0; i < n + 1; ++i) sort(adj[i].begin(), adj[i].end());
	/*
	for (int i = 0; i < n + 1; ++i) {
		cout << i << endl;
		for (auto x : adj[i]) cout << x << " ";
		cout << endl << endl;
	}
*/
	int seq[n], pos[n + 1], nc[n + 1] = {};
	int ii = 0;
	dfs(adj, seq, pos, nc, 1, ii);
/*
	for (int i = 0; i < n; ++i) cout << seq[i] << " ";
	cout << endl;
	for (int i = 1; i < n + 1; ++i) cout << pos[i] << " ";
*/


	while (q--) {
		int r1, r2;
		scanf("%d %d", &r1, &r2);
		int p = pos[r1];
		//cout << p << endl;
		printf("%d\n", r2 > nc[r1] + 1 ? -1 : seq[p + r2 - 1]);
	}

    return 0;
}
