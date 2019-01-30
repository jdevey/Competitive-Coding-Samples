#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    int n, k;
    cin >> n >> k;
    int a[n];
    fl (i, 0, n) cin >> a[i];

    map <int, int> m;
    fl (i, 0, n) ++m[a[i]];

    int mx = 0;
    for (auto x : m) mx = max(mx, x.second);

    int cnt = (mx - 1) / k + 1;

    cout << m.size() * cnt * k - n << endl;

    return 0;
}
