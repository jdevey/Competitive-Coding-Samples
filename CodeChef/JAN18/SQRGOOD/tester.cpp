#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <random>
#include <ctime>

#define BASEL 0.392072898146L //1 - 6/pi^2
#define MX 25505461 //1e7 / BASEL
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

	int n;
	cin >> n;

	int top = 1000;

	vector <int> vv;

	for (int i = 2; i < (int)sqrt(top); ++i) {
		int sq = i * i;
		for (int j = sq; j < top; j += sq) {
			vv.push_back(j);
		}
	}

	sort(vv.begin(), vv.end());

	fl (i, vv.size() - 1) if (vv[i] == vv[i + 1]){ vv.erase(vv.begin() + i + 1); --i;}

	fl (i, vv.size()) cout << vv[i] << endl;

    return 0;
}
