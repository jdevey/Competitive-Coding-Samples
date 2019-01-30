//#pragma GCC optimize("03")

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <utility>

#define ll long long
#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))

using namespace std;

void solve(int a[], int b[], int n) {

    int placeCount = 0;
    int arrStart = 0, arrComp = 0;

    while (placeCount < n - 4) {

        if (b[arrStart] == 0) {
            for (int i = arrStart; i < n; ++i) {
                if (a[i] != a[arrComp]) {
                    if (n == 5) {
                        cout << "";
                    }
                    b[i] = a[arrComp];
                    ++arrComp;
                    ++placeCount;
                    break;
                }
            }
        }
        else ++arrStart;
    }

    int smallList[4];
    int ind = 0;
    fl (i, n) {
        if (b[i] == 0) {
            smallList[ind] = i;
            ++ind;
            //cout << "";
        }
    }

    //Finding duplicates in smallList
    pair <int, int> p;
    p.first = -1;
    fl (i, 4) {
        for (int j = i + 1; j < 4; ++j) {
            if (a[smallList[i]] == a[smallList[j]]) {
                p.first = smallList[i];
                p.second = smallList[j];
                break;
            }
        }
        if (p.first != -1) break;
    }

    //Choosing values for the final four or less
    if (p.first == -1) {
        //Setting the far-right case
        b[smallList[3]] = a[smallList[0]];
        fl (i, 3) {
            b[smallList[i]] = a[smallList[i + 1]];
        }
    }
    else {
        if (n == 5) {
            cout << "";
        }
        //Finding the third and fourth
        int third = -1, fourth = -1;
        fl (i, 4) {
            if (smallList[i] != p.first && smallList[i] != p.second) {
                third = smallList[i];
                break;
            }
        }
        fl (i, 4) {
            if ((smallList[i] != p.first && smallList[i] != p.second) && smallList[i] != third) {
                fourth = smallList[i];
                break;
            }
        }

        b[third] = a[p.first];
        b[fourth] = a[p.second];

        b[p.first] = a[third];
        b[p.second] = a[fourth];
    }
}

int main() {

    ifstream finz("zin.txt");

    int t, n;

    finz >> t;

    while (t--) {

        finz >> n;
        int a[n], b[n];
        memset(b, 0, sizeof(int) * n);

        fl (i, n) finz >> a[i];

        if (n == 1) {
            cout << 0 << endl << a[0] << endl;
            continue;
        }
        else if (n == 2) {
            if (a[0] == a[1]) {
                cout << 0 << endl << a[0] << " " << a[0] << endl;
                continue;
            }
            else {
                cout << 2 << endl << a[1] << " " << a[0] << endl;
                continue;
            }
        }
        else if (n == 3) {
            if (a[0] == a[1]) {
                cout << 2 << endl << a[0] << " " << a[2] << " " << a[1] << endl;
                continue;
            }
            else if (a[0] == a[2]) {
                cout << 2 << endl << a[0] << " " << a[1] << " " << a[2] << endl;
                continue;
            }
            else if (a[1] == a[2]) {
                cout << 2 << endl << a[0] << " " << a[2] << " " << a[1] << endl;
                continue;
            }
            else {
                cout << 3 << endl << a[1] << " " << a[2] << " " << a[0] << endl;
                continue;
            }
        }

        solve(a, b, n);

        cout << n << endl;
        fl (i, n) cout << b[i] << " ";
        cout << endl;
    }

    return 0;
}