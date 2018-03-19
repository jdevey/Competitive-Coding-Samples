#include <iostream>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

	#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
	#endif

	int t, n;
	cin >> t;

	while (t--) {
		cin >> n;
		int a[n], b[n];
		fl (i, 0, n) cin >> a[i];
		fl (i, 0, n) cin >> b[i];

		bool fGood = true, bGood = true;

		fl (i, 0, n) if (a[i] > b[i]) fGood = false;
		fl (i, 0, n) if (a[n - i - 1] > b[i]) bGood = false;

		if (fGood && bGood) cout << "both" << endl;
		else if (fGood) cout << "front" << endl;
		else if (bGood) cout << "back" << endl;
		else cout << "none" << endl;
	}

	return 0;
}


