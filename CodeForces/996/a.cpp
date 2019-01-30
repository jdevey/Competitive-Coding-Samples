#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int a[] = {100, 20, 10, 5, 1};
	int n, cnt = 0;
	cin >> n;
	while (n) {
		for (int i = 0; i < 5; ++i) {
			if (a[i] <= n) {
				++cnt;
				n -= a[i];
				break;
			}
		}
	}

	cout << cnt;

    return 0;
}
