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

class LST {
	int val;
	LST* next;
	LST (int _val) {
		val = _val;
	}
};

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
	bool nul[q] = {};

	fl (i, q - 1) {
		if (!nul[i]) {
			for (int j = i + 1; j < q; ++j) {
				//cout << x[i] << " " << x[j] << " " << (x[i] & x[j]) << " " << ((x[i] & x[j]) == x[j]) << endl;
				if ((x[j] & x[i]) == x[j]) nul[j] = true;
			}
		}
	}
/*
	fl (i, q) cout << (nul[i] ? 1 : 0) << " ";
	cout << endl;
*/
	int run = n;
	fl (i, q) {
		//cout << "r " << run << endl;
		if (nul[i] == true) cout << run << endl;
		else {
			fl (j, n) {
				if (!dead[j] && (x[i] & j) == j) {
					dead[j] = true;
					--run;
				}
			}
			cout << run << endl;
		}
	}

    return 0;
}
