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

void shoot(int x, const bool* dead, int n, int& liveCount) {
	vector <bool> binary;
	int xx = x;
	while (xx != 0) {
		binary.push_back(xx % 2);
		xx /= 2;
	}

	int sz = sz(binary);
	if (x < n) dead[x] = true;

	fl (i, sz) {
		if (binary[i])
	}


}

int main() {

    int n, q;
	cin >> n;
	int h[n];
	fl (i, n) cin >> h[i];
	cin >> q;
	int x[q];
	{
		int dump;
		fl (i, q) {cin >> x[i] >> dump;}
	}

	bool dead[n] = {};

	int liveCount = n;
	fl (i, q) {
		shoot(x[i], dead, n, liveCount);
		cout << liveCount << endl;
	}

    return 0;
}
