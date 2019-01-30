//#pragma GCC optimize("03")

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstring>
#include <deque>

#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))

using namespace std;

typedef long long ll;
typedef vector <vector <int>> vvi;

int main() {

    //ifstream cin("zin.txt");

    int t, n;

    cin >> t;

    while (t--) {
        cin >> n;

        deque <int> d (n, 0);

        fl (i, n) cin >> d[i];

        fl (h, n) {
            int invCount = 0;
            d.push_back(d[0]);
            d.pop_front();
            fl (i, n) {
                for (int j = i + 1; j < n; ++j) {
                    if (d[i] > d[j]) ++invCount;
                }
            }
            cout << invCount << " ";
        }
        cout << endl;
    }

    return 0;
}