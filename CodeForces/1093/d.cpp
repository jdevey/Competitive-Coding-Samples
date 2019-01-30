#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))
#define MD 998244353

using namespace std;

typedef long long ll;
typedef long double ld;

void dfs(vector <int>* adj, int* colors, int ind, ll& oddCnt, ll& evCnt, bool& good, int currColor) {
	if (!good) return;
	if (colors[ind] != -1) {
		if (colors[ind] != currColor) good = false;
		return;
	}
	if (currColor == 1) ++oddCnt;
	else ++evCnt;
	colors[ind] = currColor;
	for (auto x : adj[ind]) {
		dfs(adj, colors, x, oddCnt, evCnt, good, 1 - currColor);
	}
}

ll power(ll base, ll exp) {
	return exp ? power(base * base % MD, exp >> 1) * (exp & 1 ? base : 1) % MD : 1;
}

int main() {

	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		vector <int>* adj = new vector <int>[n + 1]();
		fl (i, 0, m) {
			int u, v;
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		ll prod = 1;
		ll oddCnt, evCnt;
		int colors[n + 1];
		memset(colors, -1, sizeof(colors));
		bool good = true;

		fl (i, 1, n + 1) if (colors[i] == -1) {
			oddCnt = 0, evCnt = 0;
			dfs(adj, colors, i, oddCnt, evCnt, good, 0);
			prod = prod * ((power(2, oddCnt) + power(2, evCnt)) % MD) % MD;
		}

		if (!good) {
			cout << 0 << endl;
			continue;
		}

		cout << prod << endl;
	}
	

    return 0;
}
