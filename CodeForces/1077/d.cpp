#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

#define MX 200001

using namespace std;

typedef long long ll;
typedef long double ld;

struct Node {
	ld weight;
	int ind, load, total;
	Node (int _ind, int _load, int _total) : ind(_ind), load(_load), total(_total) {weight = (ld)total / load;}
	bool operator<(const Node& other) const {
		return weight < other.weight;
	}
};

int main() {

	int n, k;
	scanf("%d %d", &n, &k);
	int a[n];
	fl (i, 0, n) scanf("%d", &a[i]);

	int cs[MX] = {};
	fl (i, 0, n) ++cs[a[i]];

	vector <pair<int, int>> freq;
	fl (i, 0, MX) if (cs[i]) freq.push_back({cs[i], i});

	priority_queue <Node> pq;

	for (auto x : freq) pq.push(Node(x.second, 1, x.first));

	map <int, int> us;
	int tt = 0;

	while (tt < k) {
		auto top = pq.top();
		pq.pop();
		++us[top.ind];
		++tt;
		pq.push(Node(top.ind, top.load + 1, top.total));
	}

	for (auto x : us) {
		fl (i, 0, x.second) printf("%d ", x.first);
	}

    return 0;
}
