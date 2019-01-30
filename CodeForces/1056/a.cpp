#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	
	int n;
	cin >> n;
	int cs[101] = {};
	fl (i, 0, n) {
	    int m;
	    cin >> m;
	    while (m--) {
	        int x;
	        cin >> x;
	        ++cs[x];
	    }
	}

	fl (i, 0, 101) {
	    if (cs[i] == n) cout << i << " ";
	}
	
    return 0;
}
