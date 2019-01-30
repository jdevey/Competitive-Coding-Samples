#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

vector <int> adj[100001];

int findEnd(bool* vis, int ind) {
	vis[ind] = true;
	if (adj[ind].size() == 1) return ind;
	for (auto x : adj[ind]) {
		if (!vis[x]) return findEnd(vis, x);
	}
	return -1;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	fl (i, 0, n - 1) {
		int a1, a2;
		scanf("%d %d", &a1, &a2);
		adj[a1].push_back(a2);
		adj[a2].push_back(a1);
	}
/*
	for (int i = 1; i < 6; ++i) {
		for (auto x : adj[i]) cout << x << " ";
		cout << endl;
	}
*/
	int pCount = 0;
	for (auto x : adj) if (x.size() > 2) ++pCount;
	if (pCount > 1) return puts("No");

	printf("Yes\n");

	int mxDeg = 0, mxInd;
	for (int i = 1; i <= 100000; ++i) {
		if (adj[i].size() > mxDeg) {
			mxDeg = adj[i].size();
			mxInd = i;
		}
	}

	printf("%d\n", mxDeg);
	bool vis[100001] = {};

	for (auto x : adj[mxInd]) {
		vis[mxInd] = true;
		int end = findEnd(vis, x);
		printf("%d %d\n", mxInd, end);
		memset(vis, 0, sizeof(vis));
	}
    return 0;
}
