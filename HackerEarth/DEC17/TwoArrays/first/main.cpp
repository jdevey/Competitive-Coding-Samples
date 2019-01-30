//#pragma GCC optimize("03")

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstring>

#define ll long long
#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))

using namespace std;

int findMatches(vector <vector <int>>& matches, int firstI, int firstJ, int secI, int secJ) {

    int sum = 0;

    for (int k = firstI; k <= firstJ; ++k) {
        fl (m, matches[k].size()) {
            if (matches[k][m] >= secI && matches[k][m] <= secJ) ++sum;
        }
    }

    return sum;
}

int main() {

    //ifstream cin("zin.txt");

    ll finalSum = 0;

    int n, m, k;

    cin >> n >> m >> k;
    int a[n], b[m];

    fl (i, n) cin >> a[i];
    fl (i, m) cin >> b[i];

    if (k > min(n, m)) {cout << 0; return 0;}

    //Determining big vs small
    int big = 0, small = 0;
    if (n > m) {big = n; small = m;}
    else {big = m; small = n;}

    //Array that tells you how many matches are on a segment
    int matchSum[small];
    memset(matchSum, 0, sizeof(int) * small);
    matchSum[0] = a[0] == b[0] ? 1 : 0;
    for (int i = 1; i < small; ++i) matchSum[i] = matchSum[i - 1] + (a[i] == b[i] ? 1 : 0);

    //Building the vector that tells you the matches for everything
    vector <vector <int>> matches;
    vector <int> emptyVec;
    fl (i, small) matches.emplace_back(emptyVec);
    fl (i, small) {
        for (int j = i + 1; j < small - 1; ++j) {
            if (a[i] == b[i]) {
                matches[i].push_back(j);
            }
        }
    }

    //Counting up subarrays that align perfectly on top of one another
    for (int i = k; i <= small; ++i) {
        if (matchSum[i - 1] + findMatches(matches, 0, i - 1, 0, i - 1) >= k) ++finalSum;
        for (int j = 1; j < small - i + 1; ++j) {
            if (matchSum[j + i - 1] - matchSum[j - 1] + findMatches(matches, j - 1, j + i - 1, j - 1, j + i - 1) >= k) ++finalSum;
        }
    }

    //Counting up subarrays where the top is leading
    for (int i = k + 1; i <= small; ++i) {

        for (int h = 1; h < min(big - i + 1, i - k + 1); ++h) {
            if (matchSum[i - 1] - matchSum[h - 1] + findMatches(matches, 0, i - 1, h - 1, h + i - 1) >= k) ++finalSum;
        }

        for (int j = 1; j < small - i + 1; ++j) {
            for (int h = j + 1; h < min(big - i + 1, j + i - k + 1); ++h) {
                if (matchSum[j + i - 1] - matchSum[h - 1] + findMatches(matches, j, j + i - 1, h - 1, h + i - 1) >= k) ++finalSum;
            }
        }
    }

    //Counting up subarrays where the bottom is leading
    for (int i = k + 1; i < small; ++i) {

        for (int h = 1; h < min(small - i + 1, i - k + 1); ++h) {
            if (matchSum[i - 1] - matchSum[h - 1] + findMatches(matches, 0, i - 1, h - 1, h + i - 1) >= k) ++finalSum;
        }

        for (int j = 1; j < small - i; ++j) {
            for (int h = j + 1; h < min(small - i + 1, j + i - k + 1); ++h) {
                if (matchSum[j + i - 1] - matchSum[h - 1] + findMatches(matches, j, j + i - 1, h - 1, h + i - 1) >= k) ++finalSum;
            }
        }
    }

    cout << finalSum;

    return 0;
}