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
	string a;
	cin >> n;
	vector <int> v;
	fl (i, 0, n) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	vector <int> vc;
	fl (i, 0, n) vc.push_back(v[i]);

	cin >> a;

	int oInd = 0, cnt = 0;
	fl (i, 0, n - 1) {
		if (!(a[i] - '0')) {
			if (cnt > 0) sort(vc.begin() + oInd, vc.begin() + oInd + cnt + 1);
			oInd = i + 1;
			cnt = 0;
		}
		else {
			++cnt;
		}
	}
	if (a[n - 1] - '0') sort(vc.begin() + oInd, vc.end());

	sort(v.begin(), v.end());

	bool good = true;
	fl (i, 0, n) if (v[i] != vc[i]) good = false;

	cout << (good ? "YES" : "NO");

    return 0;
}
