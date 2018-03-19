#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define TOP 20000000
#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))
/*
#ifndef ONLINE_JUDGE
	#define cin fin
	std::ifstream fin("zin.txt");
#endif
*/
using namespace std;

typedef long long ll;

void sieve(bool* sv, vector <int>& vi) {
	for (int i = 2; i <= TOP; ++i) {
		if (!sv[i]) vi.push_back(i);
		for (int j = 2 * i; j <= TOP; j += i) sv[j] = true;
	}
}

int main() {

	auto sv = new bool[TOP + 1];
    memset(sv, 0, sizeof(sv));
	sv[0] = true; sv[1] = true;
	vector <int> vi, vx;
	sieve(sv, vi);
    vx.push_back(3);
	fl (i, 0, vi.size()) if (!sv[i]) vx.push_back(vi[i - 1]);

	int t, n;
	cin >> t;

	while (t--) {
		cin >> n;
        if (vi[n] > TOP) cout << -1;
		else cout << vx[n] << endl;
	}

    return 0;
}

