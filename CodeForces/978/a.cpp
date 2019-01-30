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

	int cs[1001] = {};
	deque <int> d;

	for (int i = n - 1; i > -1; --i) {
		if (!cs[a[i]]) {
			cs[a[i]] = true;
			d.push_front(a[i]);
		}
	}

	cout << d.size() << endl;
	fl (i, 0, d.size()) cout << d[i] << " ";

    return 0;
}
