#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define MX 10001
#define BIG 10000009
#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {

	auto f = new ll*[MX];
	fl (i, 0, MX) {
		f[i] = new ll[MX];
		memset(f[i], 0, sizeof(f[i]));
	}

	fl (i, 0, MX) f[i][0] = 1;
	fl (i, 1, MX) fl (j, 1, i + 1) f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % BIG;

	ll t, n;
	cin >> t;
	
	while (t--) {
		cin >> n;
		fl (i, 0, n + 1) cout << f[n][i] << " ";
		cout << endl;
	}
	
    return 0;
}

