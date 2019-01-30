#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define BG 200000
#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

#ifndef ONLINE_JUDGE
	#define cin fin
	std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;

int main() {

	int n, k, q;
	cin >> n >> k >> q;
	pair <int, int> rec[n];
	fl (i, 0, n) cin >> rec[i].first >> rec[i].second;

	ll diffArr[BG + 2] = {};
	fl (i, 0, n) {
		++diffArr[rec[i].first];
		--diffArr[rec[i].second + 1];
	}

	bool gd[BG + 2] = {};
	ll run = 0;
	fl (i, 0, BG + 3) {
		run += diffArr[i];
		gd[i] = run >= k;
	}

	auto ps = new int[BG + 2];
	memset(ps, 0, sizeof(ps));
	fl (i, 1, BG + 2) ps[i] += ps[i - 1] + gd[i];

	while (q--) {
		int a, b;
		cin >> a >> b;
		cout << ps[b] - ps[a - 1] << endl;
	}

    return 0;
}
