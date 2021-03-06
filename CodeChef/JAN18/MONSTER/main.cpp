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
#define fle(i,l,u) for(int (i) = (l);(i) < (u); ++(i))
#define ea(it,a) for(auto (it) = (a).begin(); (it) != (a).end(); ++(it))
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

    int n, q;

	cin >> n;
	ll a[n];
	fl (i, n) cin >> a[i];
	cin >> q;
	ll b1[q], b2[q];
	fl (i, q) cin >> b1[i] >> b2[i];

	bool deads[n] = {};
	int liveCount = n;
	fl (i, q) {
		fl (j, n) {
			if ((j & b1[i]) == j) {
				a[j] -= b2[i];
				if (!deads[j] && a[j] < 1) {
					--liveCount;
					deads[j] = true;
				}
			}
		}
		cout << liveCount << endl;
	}

    return 0;
}

