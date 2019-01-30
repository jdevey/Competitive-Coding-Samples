#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

struct Node {
	int cost, party, ind;
	Node(int _cost, int _party, int _ind) : cost(_cost), party(_party), ind(_ind) {}
	bool operator<(const Node& other) const {
		return cost < other.cost;
	}
	bool operator>(const Node& other) const {
		return cost > other.cost;
	}
};

int main() {

	int n, m;
	cin >> n >> m;

	vector <Node> b;
	fl (i, 0, n) {
		int party, cost;
		cin >> party >> cost;
		--party;
		b.push_back(Node(cost, party, i));
	}
	vector <Node> a = b;
	sort(a.begin(), a.end());
	for (int i = 0; i < n; ++i) a[i].ind = i;

	int cs[m] = {};
	fl (i, 0, n) ++cs[a[i].party];

	ll total = 1e18;
	int mx = 0;

	fl (i, 1, m) mx = max(mx, cs[i]);

	vector <Node> lists[m];
	fl (i, 0, n) lists[a[i].party].push_back(a[i]);
	fl (i, 0, m) sort(lists[i].begin(), lists[i].end(), greater<>());

	for (int i = mx; i > -1; --i) {
		ll currSum = 0;
		bool omit[n] = {};
		int cnt = cs[0];
		for (int j = 1; j < m; ++j) {
			for (int k = i; k < lists[j].size(); ++k) {
				currSum += lists[j][k].cost;
				omit[lists[j][k].ind] = true;
				++cnt;
			}
		}
		for (int j = 0; j < n; ++j) {
			if (!omit[j] && a[j].party) {
				++cnt;
				currSum += a[j].cost;
			}
			if (cnt > i) break;
		}
		total = min(total, currSum);
	}

	cout << total << endl;

	return 0;
}

