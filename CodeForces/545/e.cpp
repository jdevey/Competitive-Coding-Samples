#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

struct ND {
	int pt, weight, id, dist;
	ND(int _pt, int _weight, int _id, int _dist) {
		pt = _pt;
		weight = _weight;
		id = _id;
		dist = _dist;
	}
	bool operator<(const ND& rhs) const {
		return dist > rhs.dist;
	}
};

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	vector <ND>* v = new vector <ND>[300001];
	ll* dist = new ll[300001], *lastVal = new ll[300001], *ans = new ll[300001], sm = 0;
	bool* vis = new bool[300001];

	for (int i = 0; i < 300001; ++i) {dist[i] = 1ll << 50; lastVal[i] = 1ll << 50; ans[i] = -1; vis[i] = false;}

	int n, m, u, currNode;
	scanf("%d %d", &n, &m);
	fl (i, 0, m) {
		int a1, a2, wh;
		scanf("%d %d %d", &a1, &a2, &wh);
		v[a1].push_back(ND(a2, wh, i + 1, 0));
		v[a2].push_back(ND(a1, wh, i + 1, 0));
	}
	scanf("%d", &u);
/*
	if (n == 6 && m == 8) {
		cout << 230 << endl;
		cout << "1 4 5 6 7" << endl;
		return 0;
	}
*/
	priority_queue <ND> q;
	q.push(ND(u, 0, -1, 0));
	lastVal[u] = 0;
	dist[u] = 0;
	vis[u] = true;
	
	while (!q.empty()) {
		currNode = q.top().pt;
		q.pop();
		for (auto x : v[currNode]) {
			if (dist[currNode] + x.weight <= dist[x.pt] && x.weight < lastVal[x.pt]) {
				dist[x.pt] = dist[currNode] + x.weight;
				ans[x.pt] = x.id;
				lastVal[x.pt] = x.weight;
			}
			if (!vis[x.pt]) {q.push(ND(x.pt, x.weight, x.id, dist[x.pt])); vis[x.pt] = true;}
		}
	}

	fl (i, 1, n + 1) sm += lastVal[i];
	printf("%lld\n", sm);
	fl (i, 0, 300001) if (ans[i] != -1) printf("%lld ", ans[i]);
	printf("\n");

	return 0;
}
