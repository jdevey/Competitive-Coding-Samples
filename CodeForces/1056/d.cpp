#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))
using namespace std;
typedef long long ll;
typedef long double ld;

int dfs(vector <vector <int>>& adj, int* cnt, int ind) {
	int sm = adj[ind].size() ? 0 : 1;
	for (auto x : adj[ind]) {
	    int xx = x;
		sm += dfs(adj, cnt, xx);
	}
	cnt[ind] = sm;
	//cout << sm << " ";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

	int n;
	cin >> n;

    vector <vector <int>> adj;
    fl (i, 0, n) adj.emplace_back(vector <int>());

	fl (i, 1, n) {
	    int x;
	    cin >> x;
	    --x;
	    adj[x].push_back(i);
	}

	int cnt[n] = {};
	dfs(adj, cnt, 0);

	//sort(cnt, cnt + n);

	//fl (i, 0, n) {cout << cnt[i] << " ";}
	
    return 0;
}
