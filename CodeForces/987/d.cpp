#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

vector <int> adj[100001];

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, m, s, k;
	scanf("%d", &n, &m, &s, &k);
	int goods[n];
	fl (i, 0, n) scanf("%d", &goods[i]);
	fl (i, 0, m) {
		int a1, a2;
		--a1, --a2;
		scanf("%d %d", &a1, &a2);
		adj[a1].push_back(a2);
		adj[a2].push_back(a1);
	}

	vector <int> buckets[k], **mins;
	mins = new int*[k];
	fl (i, 0, k) mins[i] = new int[100001];
	fl (i, 0, k) fl (j, 0, n) mins[i][j] = 1e9;

	fl (i, 0, n) buckets[goods[i]].push_back(i);
	
	fl (i, 0, k) {
		queue <int> q;
		fl (j, 0, buckets[i].size()) q.push(buckets[i][j]);
		bool vis[n] = {};
		int dist[n];
		fl (j, 0, n) dist[j] = 1e9;
		fl (j, 0, k) dist[buckets[i][j]] = 0;

		while (!q.empty()) {
			vis[q.front()] = true;
			mins[i][q.front()] = dist[i][q.front()];
			for (auto x : adj[q.front()]) {
				dist[i][x] = min(dist[i][x], dist[i][q.front() + 1]);
				if (!vis[x]) q.push(x);
			}
		}
	}

	int mxs[n][k];
	fl (i, 0, n) fl (j, 0, k) mxs[i][j] = mins[j][i];

	fl (i, 0, n) sort(mxs[i], mxs[i] + k);

	fl (i, 0, n) {
		int sm = 0;
		fl (j, 0, s) {
			sm += mxs[i][j];
		}
		cout << sm << endl;
	}

    return 0;
}
