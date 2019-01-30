#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int a, b, c, n, rem;
	cin >> a >> b >> c >> n;
	rem = n;
	rem -= c;
	a -= c;
	b -= c;
	if (rem < 1 || a < 0 || b < 0) return puts("-1");
	rem -= a;
	rem -= b;
	if (rem < 1) return puts("-1");
	cout << rem << endl;

    return 0;
}
