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
	pair <int, int> a[n];
	fl (i, 0, n) cin >> a[i].first >> a[i].second;

	if (n == 1) return puts("1");

	int cnt = 2, fall[n] = {};
	fall[0] = -1;

	fl (i, 1, n - 1) {
		if (fall[i - 1] == -1 || fall[i - 1] == 0) {
			if (a[i].first - a[i].second > a[i - 1].first) {
				++cnt;
				fall[i] = -1;
			}
			else if (a[i].first + a[i].second < a[i + 1].first) {
				++cnt;
				fall[i] = 1;
			}
		}
		else if (fall[i - 1] == 1) {
			if (a[i].first - a[i].second > a[i - 1].first + a[i - 1].second) {
				++cnt;
				fall[i] = -1;
			}
			else if (a[i].first + a[i].second < a[i + 1].first) {
				++cnt;
				fall[i] = 1;
			}
		}
	}

	cout << cnt << endl;

    return 0;
}
