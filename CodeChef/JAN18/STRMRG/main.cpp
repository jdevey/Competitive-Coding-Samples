#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <utility>
#include <set>

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
/*
int lcs(string X, string Y, int n, int m) {
    int L[n+1][m+1];
    fl (i, n + 1) {
        fl (j, m + 1) {
            if (i == 0 || j == 0) L[i][j] = 0;
  	        else if (X[i-1] == Y[j-1])L[i][j] = L[i-1][j-1] + 1;
            else L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    return L[n][m];
}
*/
/*
int lcs(string X, string Y, int n, int m) {
	int L[n + 1][m + 1];
	fl (i, n + 1) {
		fl (j, m + 1) {
			if (i == 0 || j == 0) L[i][j] = 0;
			else if (X[i - 1] == Y[j - 1]) L[i][j] = L[i - 1][j - 1] + 1;
			else L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}
	return L[n][m];
}
*/

int lcs(string a, string b, int n, int m) {
	auto aa = new int*[n + 1];
	fl (i, n + 1) aa[i] = new int[m + 1];

	fl (i, n + 1) {
		fl (j, m + 1) {
			if (i == 0 || j == 0) aa[i][j] = 0;
			else if (a[i - 1] == b[j - 1]) aa[i][j] = aa[i - 1][j - 1] + 1;
			else aa[i][j] = max(aa[i - 1][j], aa[i][j - 1]);
		}
		if (i > 0) delete aa[i - 1];
	}
	int ans = aa[n][m];

	delete aa[n];
	delete aa;

	return ans;
}

int main() {

    int a, b, c, d, e, f, g, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

    cin >> t;

    while (t--) {
        string a, b;
        cin >> n >> m >> a >> b;

        int rmCount1 = 0, rmCount2 = 0;
        string t1, t2; //Shortening the strings as repeated letters are irrelevant
        fl (i, n - 1) {
            if (a[i] != a[i + 1]) t1 += a[i];
            else ++rmCount1;
        }
        fl (i, m - 1) {
            if (b[i] != b[i + 1]) t2 += b[i];
            else ++rmCount2;
        }
        t1 += a.back(); t2 += b.back();

        cout << n + m - rmCount1 - rmCount2 - lcs(t1, t2, t1.size(), t2.size()) << endl;
    }

    return 0;
}


