#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

vector <int> adj[300001];

void dfs(int* parents, bool* vis, int currNode) {
	vis[currNode] = true;
	for (auto x : adj[currNode]) {
		if (!vis[x]) {
			parents[x] = currNode;
			dfs(parents, vis, x);
		}
	}
}

void dfs2(bool* vis, int forbid, int start, int currNode, ll& cnt) {
	vis[currNode] = true;
	++cnt;
	for (auto x : adj[currNode]) {
		if (!vis[x] && !(x == forbid && currNode == start)) {
			dfs2(vis, forbid, start, x, cnt);
		}
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	try {
		int n, x, y;
	scanf("%d %d %d", &n, &x, &y);
	fl (i, 0, n - 1) {
		int a1, a2;
		scanf("%d %d", &a1, &a2);
		adj[a1].push_back(a2);
		adj[a2].push_back(a1);
	}

	if (n == 1) return puts("0");
	if (n == 2) return puts("1");

	ll total = (ll)n * (n - 1);

	bool vis[n] = {};
	int parents[n];
	fl (i, 0, n) parents[i] = -1;

	dfs(parents, vis, x);

	int endForbid = parents[y];
	int currNode = y;
	while(parents[parents[currNode]] != -1) {
		currNode = parents[currNode];
	}
	int beginForbid = currNode;

	ll cnt1 = 0, cnt2 = 0;
	fl (i, 0, n) vis[i] = false;
	dfs2(vis, beginForbid, x, x, cnt1);
	dfs2(vis, endForbid, y, y, cnt2);

	total -= (ll)cnt1 * cnt2;

	cout << total;
	}
	catch (exception& e) {
		cout << -1 << endl;
	}

    return 0;
}
