#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
#include <utility>
#include <tuple>

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
	int count = 0;
	set <tuple <int, int, int>> ff;
	fl (i, 1, n + 1) {
		fl (j, 1, i) {
			int x = i ^ j;
			//cout << i << " " << j << "  " << x;
			if (x < i && x + j > i && ff.find(make_tuple(i, max(j, x), min(j, x))) == ff.end()) {++count; ff.insert(make_tuple(i, max(j, x), min(j, x)));}
			//cout << endl;
		}
	}

	cout << count;

    return 0;
}
