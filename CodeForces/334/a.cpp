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

	fl (i, 0, n) {
		fl (j, 1, n / 2 + 1) cout << i * n + j << " " << n * n - (i * n + j) + 1 << " ";
		cout << endl;
	}

    return 0;
}
