#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define BIG 899
//#define BIG 1000000007
#define INF 0x7fffffff
#define INFL 0x7fffffffffffffffLL
#define SPEED_IO ios_base::sync_with_stdio(false);
#define fl(i,n) for(int (i) = 0; (i) < (n); ++(i))
#define fle(i,l,u) for(int (i) = (int)(l);(i) < (int)(u); ++(i))
#define ea(it,a) for(auto it = (a).begin(); it != (a).end(); ++it)
#define mset(m,v) memset(m,v,sizeof(m))
#define sz(x) (x).size()

#ifndef ONLINE_JUDGE
	#define cin fin
	std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;
typedef vector <vector <int>> vvi;

int main() {

	ll t, n, m, k, q, x, y, z, a, b, c, d, e, f, g;

	cin >> a >> b;

	if (b == 1) {
		cout << a << endl;
	}
	else {
		//cout << pow(2, log2(a)) * 2 - 1 << endl;
		
		//cout << log2(a);

		ll prod = 1;
		while (prod <= a) prod *= 2;
		cout << prod - 1 << endl;
	}

    return 0;
}
