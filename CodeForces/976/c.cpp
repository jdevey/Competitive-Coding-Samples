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
	if (n == 1) return puts("-1 -1");
	pair <int, pair <int, int>> a[n];
	fl (i, 0, n) {
		cin >> a[i].first >> a[i].second.first;
		a[i].second.second = i + 1;
	}

	sort(a, a + n);

	for (int i = n - 2; i > -1; --i) {
		if (a[i].second.first >= a[i + 1].second.first) {
			cout << a[i + 1].second.second << " " << a[i].second.second << endl;
			return 0;
		}
		if (a[i].first == a[i + 1].first && a[i].second.first <= a[i + 1].second.first) {
			cout << a[i].second.second << " " << a[i + 1].second.second << endl;
			return 0;
		}
	}

	cout << "-1 -1" << endl;

    return 0;
}
