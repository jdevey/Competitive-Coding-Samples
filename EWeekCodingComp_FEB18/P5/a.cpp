#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <ext/pb_ds/assoc_container.hpp>
#include <iomanip>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))
/*
#ifndef ONLINE_JUDGE
#define cin fin
std::ifstream fin("zin.txt");
#endif
*/
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree <pair <int, int>, null_type, less <pair <int, int>>, rb_tree_tag, tree_order_statistics_node_update> INDS;

int main() {

	int n;
	cin >> n;
	int a[n];
	fl (i, 0, n) cin >> a[i];

	INDS ss;
	float num = a[0];
	ss.insert({a[0], 0});
	cout << fixed << setprecision(1) << a[0] << endl;

	fl (i, 1, n) {
		ss.insert({a[i], i});
		if (~i & 1) num = ss.find_by_order(i / 2)->first;
		else num = (ss.find_by_order(i / 2)->first + ss.find_by_order(i / 2 + 1)->first) / 2.0;
		cout << fixed << setprecision(1) << num << endl;
	}

	return 0;
}

