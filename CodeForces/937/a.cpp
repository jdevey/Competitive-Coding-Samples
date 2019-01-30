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
	int cnt = 0;
	int tp[601] = {};
	fl (i, 0, n) {
		int a;
		cin >> a;
		if (a && !tp[a]) {
			tp[a] = true;
			++cnt;
		}
	}

	cout << cnt;

    return 0;
}
