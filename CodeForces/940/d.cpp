#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))
/*
#ifndef ONLINE_JUDGE
#define cin fin
std::ifstream fin("zin.txt");
#endif
*/
using namespace std;

typedef long long ll;

int findMin(int a[], int l, int r) {
	int min = 1e9;
	fl (i, l, r + 1) if (a[i] < min) min = a[i];
	return min;
}

int findMax(int a[], int l, int r) {
	int max = -1e9;
	fl (i, l, r + 1) if (a[i] > max) max = a[i];
	return max;
}

int main() {

    int n;
	scanf("%d", &n);
	int a[n];
	char b[n];
	fl (i, 0, n) scanf("%d", &a[i]);
	scanf("%s", b);

	int lmn = -1e9, lmx = 1e9, rmn = -1e9, rmx = 1e9, streak = 4;

	fl (i, 4, n) {
		if (streak > 3) {
			if (b[i] == '0' && b[i - 1] == '0') {
				lmx = min(lmx, findMax(a, i - 4, i) - 1);
			}
			else if (b[i] == '1' && b[i - 1] == '0') {
				lmn = max(lmn, findMax(a, i - 4, i) + 1);
			}
			else if (b[i] == '0' && b[i - 1] == '1') {
				rmx = min(rmx, findMin(a, i - 4, i) - 1);
			}
			else {
				rmn = max(rmn, findMin(a, i - 4, i) + 1);
			}
		}
		else streak = b[i] == b[i - 1] ? streak + 1 : 1;
	}

	printf("%d %d", lmn, rmx);

    return 0;
}

