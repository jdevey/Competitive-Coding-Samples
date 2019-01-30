#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

void fill(bool* outlaw, bool* vis, int* key, int k, int num) {
	if (key[num] == -1) {
		int mn;
		for (int i = num; i > -1 && !vis[i] && num - i + 1 <= k; --i) mn = i;
		for (int i = mn; i < mn + k && !vis[i] && !outlaw[i] && i < 256; ++i) key[i] = mn;
		outlaw[mn] = true;
	}
	vis[num] = true;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, k;
	cin >> n >> k;
	int a[n];
	fl (i, 0, n) cin >> a[i];

	bool vis[256] = {};
	bool outlaw[256] = {};
	int key[256];
	memset(key, -1, sizeof(key));
	fl (i, 0, 256) key[i] = -1;

	fl (i, 0, n) fill(outlaw, vis, key, k, a[i]);

	fl (i, 0, n) cout << key[a[i]] << " ";
	
    return 0;
}
