#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    string s;
    cin >> s;
    int sz = s.size();

    int rows = (sz - 1) / 20 + 1;
    int base = (sz - 1) / rows + 1;

    int md = sz % rows, ind = 0;

    cout << rows << " " << base << endl;
    for (int i = 0; i < rows; ind += base - (md && i >= md), ++i) {
        cout << s.substr(ind, base - (md && i >= md)) + ((md && i >= md) ? "*": "") << endl;
    }

    return 0;
}
