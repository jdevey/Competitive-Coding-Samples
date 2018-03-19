#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
 
#define ll long long
#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))
 
using namespace std;
 
int compare (const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}
 
int main() {
 
    int n;
    ll k;
 
    cin >> n >> k;
 
    int a[n];
    ll bigSize = n * (n + 1) / 2;
    int r[bigSize];
 
    fl (i, n) cin >> a[i];
 
    int index = 0;
    int runningX = 0;
    fl (i, n)
        for (int j = i; j < n; ++j) {
            if (j == i) runningX = a[i];
            else runningX ^= a[j];
            r[index] = runningX;
            ++index;
        }
 
    qsort(r, bigSize, sizeof(int), compare);
    cout << r[k - 1];
 
    return 0;
}
