#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

ll euclidean(ll n, ll m) {
	return !m ? n : euclidean(m, n % m);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ll n, k;
	cin >> n >> k;

	ll num = pow(10, k);

	cout << n * num / euclidean(n, num) << endl;

    return 0;
}
