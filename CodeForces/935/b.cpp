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

	int n;
	cin >> n;
	string s;
	cin >> s;

	int x[n + 1], y[n + 1];
	x[0] = 0; y[0] = 0;

	fl (i, 1, n + 1) {
		if (s[i - 1] == 'U') {
			x[i] = x[i - 1];
			y[i] = y[i - 1] + 1;
		}
		else {
			x[i] = x[i - 1] + 1;
			y[i] = y[i - 1];
		}
	}

	int count = 0;
	fl (i, 2, n) {
		if (x[i] == y[i]) {
			if (x[i - 1] == x[i + 1]) ++count;
			else if (y[i - 1] == y[i + 1]) ++count;
		}
	}

	cout << count;

    return 0;
}
