#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define fl(i,n) for(int (i) = 0; (i) < (n); ++(i))

#ifndef ONLINE_JUDGE
	#define cin fin
	std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;

bool isSquare(int n) {
	if (n < 0) return false;
	long double sq = sqrt(n);
	return sq == floor(sq);
}

int main() {

    int n;
	cin >> n;
	int a[n];
	fl (i, n) cin >> a[i];

	int max = -1000000000;
	fl (i, n) if (!isSquare(a[i]) && a[i] > max) max = a[i];

	cout << max;

    return 0;
}
