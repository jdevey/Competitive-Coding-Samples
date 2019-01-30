#include <bits/stdc++.h>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, r;
	cin >> n >> r;
	bool a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	
	int ind = 0, prev = -r, rec = -r, hc = 0;
	while (ind < n) {
		if (a[ind]) rec = ind;
		//cout << "yo " << ind << endl;
		if (ind - prev == 2 * r - 1 || ind - prev >= r && ind == n - 1) {
			//cout << "hi " << ind << endl;
			if (rec == prev) {
				return puts("-1");
			}
			else {
				ind = rec;
				++hc;
				prev = rec;
			}
		}
		++ind;
	}

	cout << hc << endl;

    return 0;
}
