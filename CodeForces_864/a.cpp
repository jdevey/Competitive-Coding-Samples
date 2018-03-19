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
	int a[n];
	fl (i, 0, n) cin >> a[i];

	int tp[101]= {};
	fl (i, 0, n) ++tp[a[i]];

	vector <int> amt;
	fl (i, 0, 101) if (tp[i]) amt.push_back(tp[i]);

	bool good = true;
	if (amt.size() != 2 || amt[0] != amt[1]) good = false;

	if (good) {
		cout << "YES" << endl;
		int mx = 0, mn = 1000;
		fl (i, 0, n) {
			mx = max(mx, a[i]);
			mn = min(mn, a[i]);
		}
		cout << mx << " " << mn;
	}
	else cout << "NO";

    return 0;
}
