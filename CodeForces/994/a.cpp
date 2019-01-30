#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, m;
	cin >> n >> m;
	int a[n], b[m];
	fl (i, 0, n) cin >> a[i];
	fl (j, 0, m) cin >> b[j];

	set <int> s;
	fl (i, 0, m) s.insert(b[i]);

	vector <int> ans;
	fl (i, 0, n) if (s.find(a[i]) != s.end()) ans.push_back(a[i]);

	for (auto x : ans) cout << x << " ";

    return 0;
}
