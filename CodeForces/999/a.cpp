#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, k;
	cin >> n >> k;
	deque <int> a;
	fl (i, 0, n) {
		int a1;
		cin >> a1;
		a.push_back(a1);
	}

	fl (i, 0, n) {
		if (a.empty()) break;
		if (a.front() <= k) a.pop_front();
		if (a.empty()) break;
		if (a.back() <= k) a.pop_back();
	}

	cout << n - a.size() << endl;

    return 0;
}
