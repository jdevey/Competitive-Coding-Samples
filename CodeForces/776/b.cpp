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

bool isPrime(int n) {
	if (n < 4) return true;
	int sqt = sqrt(n);
	fl (i, 2, sqt + 1) if (n % i == 0) return false;
	return true;
}

int main() {

	int n;
	cin >> n;
	if (n < 3) cout << 1 << endl;
	else cout << 2 << endl;

	fl (i, 2, n + 2) {
		if (isPrime(i)) cout << 1 << endl;
		else cout << 2 << endl;
	}

    return 0;
}
