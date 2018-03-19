#pragma GCC optimize("03")
 
#include <iostream>
#include <fstream>
#include <cstring>
 
#define ll long long
#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))
 
using namespace std;
 
const int primes[65] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 651, 657, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313};
bool prim[65];
 
bool coPrime (int a, int b, const bool* aFac, const bool* bFac) {
    if (a == b) {
        if (a == 1) return false;
        else return true;
    }
 
    fl (i, 65) {
        if (aFac[i] == 0) continue;
        for (int j = 0; j < 65; ++j) {
            if (bFac[j] == 0) continue;
            if (i == j) return true;
        }
    }
 
    return false;
}
 
void primeRecurse(int a) {
    if (a == 1) return;
 
    fl (i, 65) {
        if (a % primes[i] == 0) {
            a /= primes[i];
            prim[i] = true;
            primeRecurse(a);
        }
    }
}
 
int main() {
 
    //ifstream cin("zin2.txt");
 
    int n;
 
    cin >> n;
 
    int a[n];
 
    fl (i, n) cin >> a[i];
 
    bool pFac[n][65];
    memset(pFac, 0, sizeof(bool) * n * 65);
 
    //Finding the factors of all numbers
    fl (i, n) {
        if (a[i] == 1) continue;
 
        memset(prim, 0, sizeof(bool) * 65);
        primeRecurse(a[i]);
        fl (j, 65) {
            pFac[i][j] = prim[j];
        }
    }
 
    ll finalSum = 0;
 
    //Finding pairs and summing accordingly
    fl (i, n) {
        for (int j = i; j < n; ++j) {
            bool match;
            match = coPrime(a[i], a[j], pFac[i], pFac[j]);
 
            if (!match) continue;
 
            finalSum += (i + 1) * (n - j);
 
            if (finalSum > 1000000000000000000) {
                cout << -1;
                return 0;
            }
        }
    }
 
    cout << finalSum;
 
    return 0;
}
