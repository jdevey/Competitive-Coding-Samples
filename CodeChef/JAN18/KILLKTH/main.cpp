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

	ll q, p, m, n;
    string s;

	cin >> s >> q;
	n = sz(s);

	string hidden;
	vector <string> lst;
	fl (i, n) {
		for (int j = i; j < n; ++j) {
			string indString;
			for (int k = i; k <= j; ++k) indString += s[k];
			lst.push_back(indString);
		}
	}
	sort(lst.begin(), lst.end());
	fl (i, lst.size()) hidden += lst[i];

	//cout << hidden << endl;

	ll g = 0;
	fl (i, q) {
		cin >> p >> m;
		ll k = p * g % m + 1;
		g += (int)hidden[k - 1];
		cout << hidden[k - 1] << endl;
	}

    return 0;
}
