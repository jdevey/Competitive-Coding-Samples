#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

vector <int> adj[200001];
int ct[200001] = {}, ed[200001] = {}, dp[200001] = {};

void edgCnt(bool* vis, int currNode, int parent, int& cnt, set <pair <int, int>>& sp) {
	if (vis[currNode]) return;
	vis[currNode] = true;
	for (auto x : adj[currNode]) {
		if (sp.find({currNode, x}) == sp.end() && sp.find({x, currNode}) == sp.end()) {
			sp.insert({currNode, x});
			++cnt;
			edgCnt(vis, x, currNode, cnt, sp);
		}
	}
}

void dfs(bool* vis, int currNode, int& cnt) {
	vis[currNode] = true;
	++cnt;
	for (auto x : adj[currNode]) {
		if (!vis[x]) {
			dfs(vis, x, cnt);
		}
	}
}

void dpp(bool* vis, int currNode, int parent, int depth, int& orig) {
	vis[currNode] = true;
	for (auto x : adj[currNode]) {
		if (x == orig && x != parent) {
			if (dp[x] == 0) dp[x] = depth + 1;
			else dp[x] = min(dp[x], depth + 1);
		}
		else {
			if (!vis[x]) {
				dpp(vis, x, currNode, depth + 1, orig);
			}
		}
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, m, a1, a2;
	scanf("%d %d", &n, &m);
	fl (i, 0, m) {
		scanf("%d %d", &a1, &a2);
		adj[a1].push_back(a2);
		adj[a2].push_back(a1);
	}

	bool vis[n + 1] = {};
	fl (i, 1, n + 1) {
		if (!vis[i]) {
			int amt = 0;
			dfs(vis, i, amt);
			ct[i] = amt;
		}
	}

	int ans = 0;

	set <pair <int, int>> sp;
	memset(vis, 0, sizeof(vis));
	fl (i, 1, n + 1) {
		if (!vis[i]) {
			int amt = 0;
			edgCnt(vis, i, -1, amt, sp);
			ed[i] = amt;
		}
	}

	memset(vis, 0, sizeof(vis));
	fl (i, 1, n + 1) {
		if (!vis[i]) {
			dpp(vis, i, -1, 0, i);
		}
	}

	fl (i, 1, n + 1) {
		if (ct[i] > 0 && ed[i] > 0 && ct[i] == ed[i] && dp[i] == ed[i]) ++ans;
	}

	cout << ans;

    return 0;
}
