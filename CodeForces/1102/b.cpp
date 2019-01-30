#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {

    int n, k;
    cin >> n >> k;
    int a[n];
    fl (i, 0, n) cin >> a[i];

    int cs[5001] = {};
    fl (i, 0, n) ++cs[a[i]];

    int mx = 0;
    fl (i, 0, 5001) mx = max(mx, cs[i]);

    bool good = n >= k && k >= mx;
    if (!good) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;

    int cs2[5001] = {}, ans[n];

    fl (i, 0, n) ans[i] = ++cs2[a[i]];

    int cs3[k] = {};
    fl (i, 0, n) ++cs3[ans[i]];

    fl (i, 1, k + 1) {
        if (cs3[i] == 0) {
            fl (j, 0, n) {
                if (cs3[ans[j]] > 1) {
                    --cs3[ans[j]];
                    ++cs3[i];
                    ans[j] = i;
                    break;
                }
            }
        }
    }

    fl (i, 0, n) cout << ans[i] << " ";

    return 0;
}
