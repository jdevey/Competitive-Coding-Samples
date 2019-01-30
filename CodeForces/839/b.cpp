#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

#ifndef ONLINE_JUDGE
	#define cin fin
	std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;

int main() {

	int n, k;
	cin >> n >> k;
	int a[k];
	fl (i, 0, k) cin >> a[i];

	int fc = 0, hc = 0, tc = 0, oc = 0, b = n, s = 2 * n, e = 0;

	fl (i, 0, k) {
		while (a[i] > 3) {
			++fc;
			--------a[i];
		}
		if (a[i] == 3) ++hc;
		else if (a[i] == 2) ++tc;
		else if (a[i] == 1) ++oc;
	}

	while (fc > 0 && b > 0) {
		--fc;
		--b;
	}

	while (fc > 0 && s > 0) {
		--fc;
		----s;
	}

	while (b > 0 && hc > 0) {
		--hc;
		--b;
	}

	while (s > 0 && hc > 0) {
		--hc;
		----s;
	}

	while (b > 0 && tc > 0) {
		--tc;
		--b;
		++e;
	}

	while (s > 0 && tc > 0) {
		--tc;
		--s;
	}

	while (e > 1 && tc > 0) {
		--tc;
		----e;
	}

	while (e > 0 && oc > 0) {
		--oc;
		--e;
	}

	while (b > 0 && oc > 0) {
		--oc;
		--b;
		++s;
	}

	while (s > 0 && oc > 0) {
		--oc;
		--s;
	}

	cout << (!fc && !hc && !tc && !oc ? "YES" : "NO");

    return 0;
}
