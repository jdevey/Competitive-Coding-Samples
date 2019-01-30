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

ll precomp[1000001];
ll prefSum[10][1000001];

ll prodDig(int n) {
	ll s = 1;
	while (n) {
		if (n % 10) s *= n % 10;
		n /= 10;
	}
	return s;
}

ll recurse(ll n) {
	return n < 10 ? n : recurse(prodDig(n));
}

int main() {
	
	fl (i, 0, 1000001) precomp[i] = recurse(i);

	fl (i, 1, 10) {
		ll sum = 0;
		fl (j, 0, 1000001) {
			if (precomp[j] == i) ++sum;
			prefSum[i][j] = sum;
		}
	}

	int q, l, r, k;
	cin >> q;

	while (q--) {
		cin >> l >> r >> k;

		//cout << prefSum[k][r] << " " << prefSum[k][l - 1] << " " << prefSum[k][r] - prefSum[k][l - 1] << endl;

		cout << prefSum[k][r] - prefSum[k][l - 1] << endl;
	}

	//fl (i, 0, 101) cout << i << " " << precomp[i] << endl;

    return 0;
}
