#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        set <pair <int, int>> s;
        for (int i = 0; i < n; ++i) {
            int a1, a2;
            cin >> a1 >> a2;
            s.insert({a1, a2});
        }
        cout << (s.size() == n ? "possible\n" : "impossible\n");
    }

    return 0;
}
