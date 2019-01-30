#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {

	int q;
	cin >> q;
	while (q--) {
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		bool found = false;
		for (int i = l1; i <= r1; ++i) {
			for (int j = l2; j <= r2; ++j) {
				if (i != j) {
					cout << i << " " << j << endl;
					found = true;
					break;
				}
			}
			if (found) break;
		}
	}

    return 0;
}
