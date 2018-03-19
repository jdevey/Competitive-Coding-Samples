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

	int t, n, k;
	cin >> t;

	while (t--) {
		cin >> n >> k;
		int a[k];
		fl (i, 0, k) cin >> a[i];

		vector <int> diffArr;
		diffArr.push_back(a[0]);
		fl (i, 1, k) diffArr.push_back(a[i] - a[i - 1]);
		diffArr.push_back(n - a[k - 1] + 1);

		int mx = 0;
		fl (i, 1, diffArr.size() - 1) diffArr[i] = diffArr[i] / 2 + 1;

		fl (i, 0, diffArr.size()) mx = max(diffArr[i], mx);

		cout << mx << endl;
	}

    return 0;
}
