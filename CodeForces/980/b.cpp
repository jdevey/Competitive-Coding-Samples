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

	cout << "YES" << endl;

	if (k & 1) {
		fl (i, 0, n) cout << '.';
		cout << endl;

		int oldK = k;

		cout << '.';
		fl (i, 0, ((n - 2) - oldK) / 2) cout << '.';
		for (int i = 0; i < n - 2 && k; ++i) {cout << '#'; --k;}
		fl (i, 0, ((n - 2) - oldK) / 2) cout << '.';
		cout << '.';
		cout << endl;
		
		cout << '.';
		fl (i, 0, k / 2) cout << '#';
		fl (i, 0, (n - 2) / 2 - k / 2) cout << '.';
		cout << '.';
		fl (i, 0, (n - 2) / 2 - k / 2) cout << '.';
		fl (i, 0, k / 2) cout << '#';
		cout << '.';
		cout << endl;

		fl (i, 0, n) cout << '.';
		cout << endl;
	}
	else {
		fl (i, 0, n) cout << '.';
		cout << endl;

		cout << '.';
		fl (i, 0, k / 2) cout << '#';
		fl (i, 0, (n - 2) - k / 2) cout << '.';
		cout << '.';
		cout << endl;

		cout << '.';
		fl (i, 0, k / 2) cout << '#';
		fl (i, 0, (n - 2) - k / 2) cout << '.';
		cout << '.';
		cout << endl;

		fl (i, 0, n) cout << '.';
		cout << endl;
	}

    return 0;
}
