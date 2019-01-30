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

	int n, m, k;
	cin >> n >> m >> k;
	char a[n][m];
	fl (i, 0, n) fl (j, 0, m) cin >> a[i][j];

	ll sum = 0;
	fl (i, 0, n) {
		int streak = 0;
		fl (j, 0, m) {
			if (a[i][j] == '.') ++streak;
			else streak = 0;
			if (streak >= k) ++sum;
		}
	}
	if (k != 1) {
		fl (i, 0, m) {
			int streak = 0;
			fl (j, 0, n) {
				if (a[j][i] == '.') ++streak;
				else streak = 0;
				if (streak >= k) ++sum;
			}
		}
	}

	cout << sum;

	return 0;
}
