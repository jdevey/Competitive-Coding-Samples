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
	fl (i, 0, n) s += 'o';

	int ob = 1, tb = 1;
	while (ob <= n) {
		s[ob - 1] = 'O';
		ob += tb;
		tb = ob - tb;
	}

	cout << s << endl;

    return 0;
}
