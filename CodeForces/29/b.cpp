#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ld L, D, V, G, R;
	cin >> L >> D >> V >> G >> R;

	ld T = D / V;

	ld rem = T - (ll)(T) / (ll)(G + R);

	bool isHit = true;
	if (rem < G) isHit = false;

	cout << fixed << setprecision(12);

	if (isHit) {
		cout << ceil(T / (G + R)) * (G + R) + (L - D) / V;
	}
	else {
		cout << L / V;
	}

    return 0;
}
