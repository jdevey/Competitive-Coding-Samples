//Good for half points

#include <iostream>
#include <fstream>
#include <cstring>

#define ll long long
#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))

using namespace std;

int main() {

    //ifstream cin("zin.txt");
    int n, q, type, index, k, total, runner;

    cin >> n >> q;

    int a[n];
    fl (i, n) cin >> a[i];

    while (q--) {
        cin >> type >> index >> k;

        if (type == 1) {
            a[index - 1] = k;
        }
        else {
            total = 0;
            runner = a[0];
            if (runner == k) ++total;
            for (int i = 1; i < index; ++i) {
                runner ^= a[i];
                if (runner == k) ++total;
            }
            cout << total << endl;
        }
    }

    return 0;
}