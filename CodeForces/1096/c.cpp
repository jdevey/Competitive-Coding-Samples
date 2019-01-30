#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int ang;
		cin >> ang;
		bool done = false;
		fl (i, 3, 361) {
			fl (j, 1, i - 1) {
				if (180 * j == i * ang) {
					done = true;
					cout << i << endl;
					break;
				}
			}
			if (done) break;
		}
		if (!done) cout << -1 << endl;
	}
    return 0;
}

