#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

#ifndef ONLINE_JUDGE
#define cin fin
std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;

int main() {

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    set <char> lst;
    fl (i, 0, n) lst.insert(s[i]);

    string ans;

    if (n >= k) {
        fl (i, 0, k) ans += s[i];
        int ind = k - 1;
        char en = *prev(lst.end(), 1);
        while (true) {
            if (s[ind] == en) {--ind; continue;}
            else {
                ans[ind] = *next(lst.find(ans[ind]), 1);
                char sm = *lst.begin();
                fl (i, ind + 1, k) ans[i] = sm;
                break;
            }
        }
    }
    else {
        ans = s;
        char sm = *lst.begin();
        fl (i, 0, k - n) ans += sm;
    }

    cout << ans;

    return 0;
}
