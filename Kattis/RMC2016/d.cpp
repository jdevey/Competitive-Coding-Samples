#include <bits/stdc++.h>

#define first f
#define second s

using namespace std;

typedef long long ll;

struct Node {
	vector <pair <int, int>> in, out;
};

struct DN {
	int from, to, w;
	DN (int _from, int _to, int _w) {
		from = _from;
		to = _to;
		w = _w;
	}
	bool operator<(const DN& other) const {
		return w > other.w;
	}
}

Node adj[1000];

int main() {

	int n, m, c;
	scanf("%d %d %d", &n, &m, &c);
	bool clients[n] = {};
	for (int i = 0; i < c; ++i) {
		int x;
		scanf("%d", &x);
		clients[x] = true;
	}
	for (int i = 0; i < n; ++i) {
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		adj[a].out.push_back({b, w});
		adj[b].in.push_back({a, w});
	}

	priority_queue <DN> pq;
	vector <int> dijParents[n];
	bool dijVis[n] = {};
	vis[0] = true;

	for (auto x : adj[0].out) {
		pq.push(DN(0, x.f, x.s));
	}

	while (!pq.empty()) {
		// TODO for each edge,
		// make vis for that node true
		// update dijParents
		// add surrounding edges to queue, but only if that node isn't visited yet
		pq.pop();
	}

	return 0;
}
