#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int findMax(vector <int>& v) {
	int mx = 0;
	fl (i, 0, v.size()) mx = max(mx, v[i]);
	return mx;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	int a[n];
	fl (i, 0, n) cin >> a[i];

	vector <int> v;

	fl (i, 0, n) v.push_back(a[i]);

	while (!v.empty()) {
		int mx = findMax(v);
		fl (i, 0, v.size() - 1) if (abs(v[i] - v[i + 1]) > 1) return puts("NO");
		fl (i, 0, v.size()) if (v[i] == mx) {v.erase(v.begin() + i); continue;}
	}

    return puts("YES");
}
