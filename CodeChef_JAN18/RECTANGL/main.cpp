//#pragma GCC optimize("03")
 
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
 
#define BIG 1000000007
#define INF 0x7fffffff
#define INFL 0x7fffffffffffffffLL
#define SPEED_IO ios_base::sync_with_stdio(false);
#define fl(i,n) for(int (i) = 0; (i) < (n); ++(i))
#define fle(i,l,u) for(int (i) = (int)(l);(i) < (int)(u); ++(i))
#define ea(it,a) for(auto (it) = (a).begin(); (it) != (a).end(); ++(it))
#define mset(m,v) memset(m,v,sizeof(m))
#define sz(x) size(x)
 
#ifndef ONLINE_JUDGE
	#define cin fin
	std::ifstream fin("zin.txt");
#endif
 
using namespace std;
 
typedef long long ll;
typedef vector <vector <int>> vvi;
 
int main() {
 
    int t, n, m, k, q, l, r, x, y, z, a, b, c, d, e, f, g;
 
	cin >> t;
 
	while (t--) {
		cin >> a >> b >> c >> d;
		cout << (a == b && c == d || a == c && b == d || a == d && b == c ? "YES" : "NO") << endl;
	}
 
    return 0;
}
