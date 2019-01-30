#include <bits/stdc++.h>

using namespace std;

int main() {

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; ++i) cin >> a[i];
		int sm = 0;
		for (int i = 0; i < n; ++i) sm += a[i];
		int maj = sm / 2 + 1;
		int mx = 0, mxc = 0, mxInd = 0;
		for (int i = 0 ; i < n; ++i) {
			if (a[i] == mx) ++mxc;
			if (a[i] > mx) {
				mx = a[i];
				mxInd = i + 1;
				mxc = 1;
			}
		}
		if (mxc > 1) cout << "no winner" << endl;
		else if (mx >= maj) cout << "majority winner " << mxInd << endl;
		else cout << "minority winner " << mxInd << endl;
	}

	return 0;
}
