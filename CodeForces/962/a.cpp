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
	int a[n];
	fl (i, 0, n) cin >> a[i];

	int run = 0, goal;
	fl (i, 0, n) run += a[i];

	goal = (run + 1) / 2;

	run = 0;

	fl (i, 0, n) {
		run += a[i];
		if (run >= goal) {
			cout << i + 1 << endl;
			return 0;
		}
	}

    return 0;
}
