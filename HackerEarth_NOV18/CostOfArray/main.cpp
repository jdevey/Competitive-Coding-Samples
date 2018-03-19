#pragma GCC optimize("03")
 
#include <iostream>
#include <fstream>
#include <vector>
 
#define MAXSWAP 1048575
#define ll long long
#define fl(x,n) for(ll (x) = 0; (x) < (n); ++(x))
 
using namespace std;
 
void swap(ll* a, ll* b) {
    ll temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
 
ll binarySearch(ll array[], ll start, ll end, ll desired) {
 
    if (desired == array[0] || desired < array[0]) {
        return 0;
    }
 
    while (true) {
 
        if (array[end] == desired) return end;
        else if (end - start == 1) {
            return end;
        }
        else if (desired <= array[(end + start)/2]) {
            if (desired == array[(end + start) /2 ]) return (end + start)/2;
            else end = (end + start) / 2;
        }
        else {
            start = (end + start) / 2;
        }
    }
}
 
//QUICKSORT STUFF
ll partitioner(ll start, ll end, ll array[], ll arraySister[]) {
 
    ll pivot=array[start];
    ll i=start-1;
    ll j=end+1;
 
    while(true) {
        do {
            i++;
        } while (array[i]<pivot);
 
        do {
            j--;
        } while (array[j]>pivot);
 
        if (i>=j) return j;
 
        swap(&array[i], &array[j]);
        swap(&arraySister[i], &arraySister[j]);
    }
 
}
 
void quicksort(ll start, ll end, ll array[], ll arraySister[]) {
 
    if (start<end) {
 
        ll p=partitioner(start, end, array, arraySister);
 
        //Lower quicksort
        quicksort(start, p, array, arraySister);
 
        //Higher quicksort
        quicksort(p+1, end, array, arraySister);
    }
    else return;
}
 
int main() {
 
    ll n, m;
 
    cin >> n;
 
    auto a = new ll[n];
    auto b = new ll[n];
    auto aPos = new ll[n];
    auto bPos = new ll[n];
    auto aCopy = new ll[n];
    auto bCopy = new ll[n];
 
 
    fl (i, n) cin >> a[i];
    fl (i, n) aPos[i] = i;
    fl (i, n) cin >> b[i];
    fl (i, n) bPos[i] = i;
    fl (i, n) aCopy[i] = a[i];
    fl (i, n) bCopy[i] = b[i];
 
    cin >> m;
 
    //ll cost [m][m];
    auto cost = new ll*[m];
    for(int i = 0; i < m; ++i)
        cost[i] = new ll[m];
 
    fl (i, m)
        fl (j, m)
            cin >> cost[i][j];
 
    quicksort(0, n - 1, a, aPos);
    quicksort(0, n - 1, b, bPos);
 
    vector <ll> fVec;
    vector <ll> sVec;
    int swapCount = 0;
    
    fl (j, 300) {
        fl (i, n) {
            if (swapCount >= MAXSWAP) break;
            ll aInd = aPos[i];
            ll bInd = bPos[i];
 
            //If the switch is profitable, in other words
            if (bCopy[aInd] * aCopy[bInd] + bCopy[bInd] * aCopy[aInd] - cost[aCopy[aInd]][aCopy[bInd]] >
                aCopy[aInd] * bCopy[aInd] + aCopy[bInd] * bCopy[bInd]) {
                fVec.push_back(aInd + 1);
                sVec.push_back(bInd + 1);
                swap(&aCopy[aInd], &aCopy[bInd]);
                ll searched = binarySearch(aCopy, 0, n - 1, bPos[i]);
                swap(&aPos[i], &aPos[searched]);
                ++swapCount;
            }
        }
        if (swapCount >= MAXSWAP) break;
    }
 
    cout << fVec.size() << endl;
    fl(i, fVec.size()) cout << fVec[i] << " " << sVec[i] << endl;
 
    return 0;
}
