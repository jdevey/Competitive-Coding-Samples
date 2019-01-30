#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int getBelow(int* a, int n, int val) {
	return lower_bound(a, a + n, val) - a;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, k;
	scanf("%d %d", &n, &k);
	pair <int, int> a[n];
	fl (i, 0, n) {scanf("%d", &a[i].first); a[i].second = i;}

	int aCopy[n];
	fl (i, 0, n) aCopy[i] = a[i].first;

	vector <int> adj[n];
	fl (i, 0, k) {
		int a1, a2;
		scanf("%d %d", &a1, &a2);
		--a1; --a2;
		adj[a1].push_back(aCopy[a2]);
		adj[a2].push_back(aCopy[a1]);
	}

	sort(a, a + n);
	sort(aCopy, aCopy + n);

	int ans[n];

	fl (i, 0, n) {
		if (a[i].first == a[0].first) {
			ans[a[i].second] = 0;
		}
		else {
			int cnt = getBelow(aCopy, n, aCopy[i]);
			for (auto x : adj[a[i].second]) {
				if (x < aCopy[i]) --cnt;
			}
			ans[a[i].second] = cnt;
		}
	}

	fl (i, 0, n) cout << ans[i] << " ";

    return 0;
}
