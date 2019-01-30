#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, m;
	cin >> n >> m;

	multimap <int, pair <int, int>> mp;

	fl (i, 0, m) {
		int a, b, w;
		cin >> a >> b >> w;

		if (mp.find(a) == mp.end()) {
			mp.insert({b, {w, 1}});
		}
		else {
			auto it = mp.find(a);
			
		}
		++sn[Node(
	}

    return 0;
}
