#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <ctime>

#define BIG 1000000007
#define INF 0x7fffffff
#define INFL 0x7fffffffffffffffLL
#define SPEED_IO ios_base::sync_with_stdio(false);
#define fl(i,n) for(int (i) = 0; (i) < (n); ++(i))
#define fle(i,l,u) for(int (i) = (l);(i) < (u); ++(i))
#define ea(it,a) for(auto (it) = (a).begin(); (it) != (a).end(); ++(it))
#define mset(m,v) memset(m,v,sizeof(m))
#define sz(x) (x).size()

#ifndef ONLINE_JUDGE
	#define cin fin
	std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector <vector <int>> vvi;

clock_t start = clock();

ull makeNum(const int* a, n) {
	ull sum = 0;
	for (int i = n - 1, i > -1; --i) sum += a[i] * pow(10, i);
	return sum;
}

int main() {

	int n, pos, l, r;
	cin >> n >> pos >> l >> r;

	if (r == n && l == 1) cout << 0;
	else if (r == n) {
		if (pos >= l) cout << pos - l + 1;
		else cout << l - pos + 1;
	}
	else if (l == 1) {
		if (pos <= r) cout << r - pos + 1;
		else cout << pos - r + 1;
	}
	else if (pos <= r && pos >= l) cout << min(pos - l + (r - l) + 2, r - pos + (r - l) + 2);
	else if (pos < l) cout << 2 + r - pos;
	else if (pos > r) cout << 2 + pos - l;

    return 0;
}
