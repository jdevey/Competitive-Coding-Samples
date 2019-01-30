#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll n, k, m, a1, a2, t;
	cin >> n >> k >> m;
	vector <pair <ll, ll>> adj[n + 1];
	for (ll i = 0; i < m; ++i) {
		cin >> a1 >> a2 >> t;
		adj[a1].push_back({a2, t});
		adj[a2].push_back({a1, t});
	}
	priority_queue <pair <ll, ll>, vector <pair <ll, ll>>, greater <>> pq;
	pq.push({0, 1});
	bool vis[n + 1] = {};
	while (!pq.empty()) {
		auto fr = pq.top();
		if (fr.second == n) {
			cout << fr.first << endl;
			return 0;
		}
		pq.pop();
		vis[fr.second] = true;
		for (auto x : adj[fr.second]) {
			if (!vis[x.first]) {
				ll tm = fr.first + x.second;
				ll md = tm % (2 * k);
				if (md >= k && x.first != n) tm += 2 * k - md;
				pq.push({tm, x.first});
			}
		}
	}
	return 0;
}
