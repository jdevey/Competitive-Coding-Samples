#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <numeric>

#define INF 1e14L
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
	ll a[n + 1];
	a[0] = 0;
	fl (i, 1, n + 1) cin >> a[i];

	ll prefSum[n + 1] = {};
	partial_sum(a, a + n + 1, prefSum);

	ll count = 0;
	map <ll, int> mm;
	
	if (k == 1) {
		for (int i = n; i > -1; --i) {
			ll nd = prefSum[i] + 1;
			if (mm.find(nd) != mm.end()) count += mm[nd];
			++mm[prefSum[i]];
		}
	}
	else if (k == -1) {
		for (int i = n; i > -1; --i) {
			for (int j = -1; j < 2; j += 2) {
				ll nd = prefSum[i] + j;
				if (mm.find(nd) != mm.end()) count += mm[nd];
			}
			++mm[prefSum[i]];
		}
	}
	else {
		for (int i = n; i > -1; --i) {
			ll target = 1;
			while (abs(target) <= INF) {
				ll nd = prefSum[i] + target;
				if (mm.find(nd) != mm.end()) count += mm[nd];
				target *= k;
			}
			++mm[prefSum[i]];
		}
	}

	cout << count;

    return 0;
}
