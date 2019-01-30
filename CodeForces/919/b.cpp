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

int digSum(int n) {
	int sz = log10(n) + 1, sum = 0;
	fl (i, 0, sz) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main() {

	int k;
	cin >> k;

	int count = 0, ind = 1;
	while (count < k) {
		if (digSum(ind) == 10) ++count;
		++ind;
	}

	cout << ind - 1;

    return 0;
}
