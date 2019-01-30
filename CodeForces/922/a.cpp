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

	ll x, y;
	cin >> x >> y;

	bool good = true;
	if (y < 1) good = false;
	if (y == 1 && x != 0) good = false;
	if (~(x + y) & 1) good = false;
	if (x < y - 1) good = false;

	cout << (good ? "Yes" : "No") << endl;

    return 0;
}
