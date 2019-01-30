/*
ID: deveyjo1
TASK: wormhole
LANG: C++14            
*/
#include <bits/stdc++.h>

using namespace std;

int genTotal(int n) {
	int prod = 1;
	for (int i = n - 1; i > 1; i -= 2) prod *= i;
	return prod;
}

deque <int> genDeq(int n, int val) {
	deque <int> ans = {1};
	for (int i = 3; i < n; i += 2) {
		ans.push_front(val % i + 1);
		val /= i;
	}
	return ans;
}

bool isLoopUtil(pair <int, int>* a, int* adj, bool* vis, int& n, int ind) {
	if (vis[ind]) return true;
	vis[ind] = true;
	if (ind == n - 1) return false;
	if (a[ind].first == a[ind + 1].first) return isLoopUtil(a, adj, vis, n, adj[ind + 1]);
	return false;
}

bool isLoop(pair <int, int>* a, int* adj, int n) {
	for (int i = 0; i < n - 1; ++i) {
		bool vis[n] = {};
		if (isLoopUtil(a, adj, vis, n, i)) return true;
	}
	return false;
}

int main() {
    
	freopen("wormhole.in", "r", stdin);
	freopen("wormhole.out", "w+", stdout);

	int n, cnt = 0;
	cin >> n;
	pair <int, int> a[n];
	for (int i = 0; i < n; ++i) cin >> a[i].second >> a[i].first;

	sort(a, a + n);

	for (int i = 0; i < genTotal(n); ++i) {
		deque <int> di = genDeq(n, i);
		int adj[n];
		memset(adj, -1, sizeof(adj));
		for (int j = 0; j < n; ++j) {
			if (adj[j] == -1) {
				int ind = 0;
				for (int k = j + 1;; ++k) {
					if (adj[k] == -1) ++ind;
					if (ind == di.front()) {
						adj[j] = k;
						adj[k] = j;
						di.pop_front();
						break;
					}
				}
			}
		}
		if (isLoop(a, adj, n)) ++cnt;
	}

	cout << cnt << endl;

    return 0;
}
