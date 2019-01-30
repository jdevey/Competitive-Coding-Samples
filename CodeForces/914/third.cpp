#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define MD 1000000007
#define fl(i,m,n) for(int (i) = m; (i) < (n); ++(i))

#ifndef ONLINE_JUDGE
#define cin fin
std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;

ll ncr[1001][1001] = {};

//Build the binomial coefficients like pascal's triangle
void initNCR() {
    ncr[0][0] = 1;
    fl (i, 1, 1001) {
        fl (j, 0, 1001) {
            if (j > i) continue;
            if (j == 0) ncr[i][j] = 1;
            else ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % MD;
        }
    }
}

int numSetBits(string s) {
    int count = 0;
    fl (i, 0, s.size()) if (s[i] == '1') ++count;
    return count;
}

int numSetBits(ll n) {
    int count = 0;
    for (;n;) {
        count += n & 1;
        n /= 2;
    }
    return count;
}

int main() {

    ll total = 0;

    //Precalc stuff
    initNCR();

    int ns[1001];
    int ks[1001];
    fl (i, 1, 1001) {
        int ind = i;
        int count = 1;
        while (ind != 1) {
            ind = numSetBits(ind);
            ++count;
        }
        ks[i] = count;
    }
    fl (i, 0, 1001) ns[i] = numSetBits(i);

    string n;
    int k;
    cin >> n >> k;
    int nsb = numSetBits(n);

    if (k == 0) {
        cout << 1;
        return 0;
    }

    fl (i, 1, 1001) {
        if (ks[i] != k) continue;
        int oneCount = 0;
        fl (j, 0, n.size()) {
            if (oneCount > i) break;
            if (n[j] == '0') continue;
            total  = (total + ncr[n.size() - j - 1][i - oneCount]) % MD;
            ++oneCount;
        }
        if (nsb == i) total = (total + 1) % MD;
    }
    if (k == 1) --total;

    cout << total;

    return 0;
}
