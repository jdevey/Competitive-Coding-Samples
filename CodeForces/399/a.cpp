#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, p, k;
	cin >> n >> p >> k;

	int l, r;
	l = p - k, r = p + k;

	vector <int> inc;

	fl (i, 1, 101) if (i >= l && i <= r && i >= 1 && i <= n) inc.push_back(i);

	if (inc[0] != 1) cout << "<< ";

	for (auto x : inc) {
		if (x == p) cout << '(' << x << ')' << ' ';
		else cout << x << ' ';
	}

	if (inc.back() != n) cout << ">>";

    return 0;
}
