#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

struct Edge {
	int to, from, cost;
	bool operator<(const Edge& other) const {
		return cost < other.cost;
	}
};

int find(int* link, int x) {
	while (x != link[x]) x = link[x];
	return x;
}

bool same(int* link, int a, int b) {
	return find(link, a) == find(link, b);
}

void unite(int* link, int* size, int a, int b) {
	a = find(link, a);
	b = find(link, b);
	if (size[a] < size[b]) swap(a, b);
	size[a] += size[b];
	link[b] = a;
}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);
	Edge a[m];
	fl (i, 0, m) scanf("%d %d %d", &a[i].to, &a[i].from, &a[i].cost);

	sort(a, a + m);

	int cnt = 0;
	int link[n + 1], size[n + 1];
	fl (i, 1, n + 1) link[i] = i;
	fl (i, 1, n + 1) size[i] = 1;

	vector <vector <Edge>> div;
	fl (i, 0, m) {
		if (i == 0 || a[i].cost != a[i - 1].cost) div.emplace_back(vector <Edge>());
		div.back().push_back(a[i]);
	}

	for (auto group : div) {
		int good = 0, chosen = 0;
		for (auto e : group) if (!same(link, e.to, e.from)) ++good;
		for (auto e : group) {
			if (!same(link, e.to, e.from)) {
				unite(link, size, e.to, e.from);
				++chosen;
			}
		}
		cnt += good - chosen;
	}

	cout << cnt << endl;

    return 0;
}
