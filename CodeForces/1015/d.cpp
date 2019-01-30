#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ll n, k, s, q = 0;
	cin >> n >> k >> s;

	while ((q + 1) * (n - 1) + (k - (q + 1)) <= s) {++q; cout << q * (n - 1) + (k - q) << endl;}

	vector <ll> vll;
	fl (i, 0, q) vll.push_back(n - 1);

	ll mid = s - q * (n - 1) - (k - q) + 1;
	vll.push_back(mid);
	fl (i, 0, k - q - (mid ? 1 : 0)) vll.push_back(1);

	for (auto x : vll) cout << x << endl;

    return 0;
}

