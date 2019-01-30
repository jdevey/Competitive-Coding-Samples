#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int bs(pair <int, int>* arr, int n, int x) {
	int base = 0;
	for (int jump = n >> 1; jump; jump >>= 1) if (base + jump < n && arr[base + jump].first <= x) base += jump;
	return base;
}

int cel(int num, int denom) {
	return (num - 1) / denom + 1;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, x1, x2;
	cin >> n >> x1 >> x2;
	pair <int, int> a[n];
	fl (i, 0, n) cin >> a[i].first >> a[i].second;

	sort(a, a + n);

	fl (i, 1, n) {
		int req = cel(x1, i);
		int pt = 0;
		if (req <= a[n - 1].first) {
			pt = bs(a, n, req);
		}
		else continue;

		cout << req << " " << pt << endl;
		if (n - pt + 1 >= i) {
			cout << i << " " << n - i << endl;
			fl (j, pt, pt + i + 1) cout << a[j].second << " ";
			cout << endl;
			fl (j, 0, pt) cout << a[j].second << " ";
			fl (j, pt + i + 1, n) cout << a[j].second << " ";
			return 0;
		}
	}

    return 0;
}
