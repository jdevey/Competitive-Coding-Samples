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

	int top = n * 1.0 / BASEL * 11 / 10;
	if (top < 100) top = 100;

	bool tp[top * 3 / 2] = {};

	vector <int> vv;

	for (int i = 2; i < (int)sqrt(top); ++i) {
		int sq = i * i;
		for (int j = sq; j < top; j += sq) {
			if (!tp[j]) {vv.push_back(j); tp[j] = true;}
		}
	}

	sort(vv.begin(), vv.end());

	cout << vv[n - 1];

    return 0;
}

