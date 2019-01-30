#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, k;
	cin >> n >> k;
	int a[n];
	fl (i, 0, n) cin >> a[i];

	int cs[101] = {};
	vector <int> ans;
	for (int i = 0; i < n; ++i) {
		if (!cs[a[i]]) {
			ans.push_back(i + 1);
			cs[a[i]] = true;
		}
		if (ans.size() == k) break;
	}

	if (ans.size() < k) return puts("NO");

	cout << "YES" << endl;
	for (auto x : ans) cout << x << " ";

    return 0;
}
