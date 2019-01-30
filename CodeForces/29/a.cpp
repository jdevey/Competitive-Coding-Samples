#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	int a[n], s[n];
	fl (i, 0, n) cin >> a[i] >> s[i];

	map <int, int> m;
	fl (i, 0, n) m[a[i]] = a[i] + s[i];

	//for (auto x : m) cout << x.first << " " << x.second << endl;

	for (auto x : m) if (m.find(x.second) != m.end() && x.first == m[x.second]) return puts("YES");

    return puts("NO");
}
