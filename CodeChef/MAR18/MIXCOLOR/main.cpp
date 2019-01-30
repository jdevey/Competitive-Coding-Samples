#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

#ifndef ONLINE_JUDGE
	#define cin fin
	std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;

int main() {

	int t, n;
	cin >> t;

	while (t--) {
		cin >> n;
		int a[n];
		fl (i, 0, n) cin >> a[i];

		map <int, int> m;
		fl (i, 0, n) ++m[a[i]];

		int count = 0;
		for (auto i : m) count += i.second - 1;

		cout << count << endl;
	}

    return 0;
}
