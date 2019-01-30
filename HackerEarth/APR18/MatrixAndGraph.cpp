#include <bits/stdc++.h>

#define fl(i,a,b) for(int(i)=(a);(i)<(b);++i)

using namespace std;

typedef long long ll;

int a[257][257], b[257][257], n, m, x1, x2;
vector <int> adj[257];

ll compScore(int* perm) {
	ll sm1 = 0, sm2 = 0;
	fl (i, 0, n) {
		for (auto x : adj[i]) {
			sm1 += a[perm[i]][perm[x]];
		}
	}
	fl (i, 0, n) {
		for (auto x : adj[i]) {
			sm2 += b[perm[i]][perm[x]];
		}
	}
	return sm1 * sm2 >> 2ll;
}

void rSwap(int* perm) {
	fl (i, 0, n) swap(perm[i], perm[rand() % n]);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	clock_t start = clock();

	srand(time(NULL));

	cin >> n >> m;
	fl (i, 0, n) fl (j, 0, n) cin >> a[i][j];
	fl (i, 0, n) fl (j, 0, n) cin >> b[i][j];
	fl (i, 0, m) {
		cin >> x1 >> x2;
		adj[x1].push_back(x2);
		adj[x2].push_back(x1);
	}

	int perm[n], bestPerm[n];
	fl (i, 0, n) {perm[i] = i; bestPerm[i] = i;}

	ll mn = 0;

	do {
		rSwap(perm);
		ll score = compScore(perm);
		if (score < mn) {
			mn = score;
			fl (i, 0, n) bestPerm[i] = perm[i];
		}
	} while ((clock() - start) * 1.0 / CLOCKS_PER_SEC < 1.95);

	fl (i, 0, n) cout << bestPerm[i] << " ";
	cout << endl;

	return 0;
}
