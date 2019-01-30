#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

int main() {

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; ++i) cin >> a[i];
		int sm = accumulate(a, a + n, 0);
		int mx = 0, mc = 0, mxInd = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] == mx) ++mc;
			else if (a[i] > mx) {
				mx = a[i];
				mc = 1;
				mxInd = i + 1;
			}
		}
		if (mc > 1) cout << "no winner\n";
		else if (mx >= sm / 2 + 1) cout << "majority winner " << mxInd << endl;
		else cout << "minority winner " << mxInd << endl;
	}

	return 0;
}
