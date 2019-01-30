#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	ll n;
	cin >> n;

	ll p = 1;
	while (!(n % p)) p *= 3;

	cout << (n - 1) / p + 1 << endl;

    return 0;
}
