#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {

	int n;
	cin >> n;
	int a[n];
	fl (i, 0, n) cin >> a[i];

	fl (i, 0, n) {
		bool vis[n] = {};
		int ind = i;
		while (!vis[ind]) {
			vis[ind] = true;
			ind = a[ind] - 1;
		}
		cout << ind + 1 << endl;
	}

    return 0;
}
