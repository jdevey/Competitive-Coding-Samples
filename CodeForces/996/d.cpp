#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int find(int* a, int n, int val) {
	int cnt = 0;
	fl (i, 0, 2 * n) {
		if (a[i] == val) ++cnt;
		if (cnt == 2) return i;
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	int a[2 * n];
	fl (i, 0, 2 * n) cin >> a[i];

	int cnt = 0;

	for (int i = 0; i < 2 * n; i += 2) {
		while (true) {
			int mt = find(a, n, a[i]);
			if (mt == i + 1) break;
			swap(a[mt], a[mt - 1]);
			++cnt;
		}
	}

	cout << cnt << endl;

    return 0;
}
