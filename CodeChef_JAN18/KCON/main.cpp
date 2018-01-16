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
#define sz(x) (x).size()

#ifndef ONLINE_JUDGE
#define cin fin
std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;
typedef vector <vector <int>> vvi;

ll fm(ll& a, ll& b, ll& c) {
    return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

//Returns the sum of the elements of the contiguous subarray with the maximum total sum
ll kadane(const int* a, int n) {

    ll grandMax = a[0], currMax = a[0];

    fle(i, 1, n) {
        currMax = a[i] > a[i] + currMax ? a[i] : a[i] + currMax;
        grandMax = grandMax > currMax ? grandMax : currMax;
    }

    return grandMax;
}

int main() {

    int t, n, m, k, q, l, r, x, y, z, a, b, c, d, e, f, g;

    cin >> t;

    while (t--) {
        cin >> n >> k;
        int a[n];
        fl (i, n) cin >> a[i];
        int bigArr[2 * n];
        fl (i, 2 * n) bigArr[i] = a[i % n];

        ll sumArr[n];
        ll sum = 0;
        fl (i, n) {
            sum += a[i];
            sumArr[i] = sum;
        }
        ll bSumArr[2 * n];
        ll bSum = 0;
        fl (i, 2 * n) {
            bSum += bigArr[i];
            bSumArr[i] = bSum;
        }

        if (t == 2) {
            cout << "";
        }

        ll total = kadane(a, n);
        //cout << total << endl;

        ll bTotal = kadane(bigArr, 2 * n);
        //cout << bTotal << endl;

        ll llong = sum * k - (bSum - bTotal);

        if (total == sum) cout << total * k << endl;
        else if (k == 1) cout << total << endl;
        else cout << fm(total, bTotal, llong) << endl;
    }

    return 0;
}


