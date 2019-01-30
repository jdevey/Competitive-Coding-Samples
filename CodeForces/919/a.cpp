#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <iomanip>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

#ifndef ONLINE_JUDGE
	#define cin fin
	std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;

int main() {

	int n, m;
	cin >> n >> m;
	long double minFrac = 1000000.0;
	fl (i, 0, n) {
		long double a, b;
		cin >> a >> b;
		if (a / b < minFrac) minFrac = a / b;
	}

	cout << fixed << setprecision(12) << minFrac * m;

    return 0;
}
