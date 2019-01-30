#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll tri(ll n) {
	return n * (n + 1) / 2;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ll n, m;
	cin >> n >> m;
	ll t = n + m;
	
	ll gl = 0;
	while (tri(gl + 1) <= t) ++gl;

	ll good[gl + 1] = {};
	ll c = n, g = gl;
	while (g) {
		if (g >= c) {good[c] = true; break;}
		else {
			c -= g;
			good[g] = true;
			--g;
		}
	}
	vector <ll> aList, bList;
	for (int i = 1; i <= gl; ++i) if (good[i]) aList.push_back(i);
	for (int i = 1; i <= gl; ++i) if (!good[i]) bList.push_back(i);

	cout << aList.size() << endl;
	for (auto x : aList) cout << x << " ";
	cout << endl << bList.size() << endl;
	for (auto x : bList) cout << x << " ";
	cout << endl;


    return 0;
}
