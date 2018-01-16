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

    ll a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

    cin >> t;

    while (t--) {
        cin >> x >> n;

        ll target = n * (n + 1) / 2 - x;
        if (target & 1) {
            cout << "impossible" << endl;
            continue;
        }
        target /= 2;

        int ans[n + 1] = {};
        ans[x] = 2;

        ll sum = 0;

        int ind = n;
        bool found = false;

        while (ind > 0) {
            if (sum + ind <= target && ind != x && sum + ind + x != target) {
                sum += ind;
                ans[ind] = 1;
            }
            if (sum == target) {
                found = true;
                break;
            }
            --ind;
        }

        if (!found) {
            cout << "impossible" << endl;
            continue;
        }

        fle (i, 1, n + 1) {
/*
			if (ans[i] == 1) {
				cout << i << " ";
			}
*/
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}
