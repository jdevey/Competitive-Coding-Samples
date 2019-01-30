//DONE

//#pragma GCC optimize("03")

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
#include <ctime>

#define ll long long
#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))

using namespace std;

//clock_t start = clock();

void swapper(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
/*
void solve(int a[], int b[], int n) {

    int aCopy[n];
    fl (i, n) aCopy[i] = a[i];

    int backInd = 0, placeCount = 0;

    while (placeCount < n - 4) {
        for (int i = backInd + 1; i < n; ++i) {
            if (a[i] != a[backInd] && a[i] != aCopy[backInd]) {
                swapper(&a[i], &a[backInd]);
                b[backInd] = a[backInd];
                ++backInd;
                ++placeCount;
                break;
            }
        }
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
*/

void randomShuffle(int a[], int size) {
    fl (i, size) {
        int rNum = rand() % size;
        swapper(&a[i], &a[rNum]);
    }
}

int main() {

    //srand(time((unsigned)NULL));

    //ifstream cin("zin.txt");

    int t, n;

    cin >> t;

    while (t--) {

        cin >> n;
        int a[n], b[n];
        memset(b, 0, sizeof(int) * n);

        fl (i, n) cin >> a[i];

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

        //solve(a, b, n);

        fl(i, n) b[i] = a[i];
        randomShuffle(b, n);
        bool goodShuff = false;

        while (!goodShuff) {
            goodShuff = true;
            fl (i, n) {
                if (b[i] == a[i]) {
                    goodShuff = false;
                    break;
                }
            }
            if (!goodShuff) randomShuffle(b, n);
        }

        cout << n << endl;
        fl (i, n) cout << b[i] << " ";
        cout << endl;
    }

    return 0;
}