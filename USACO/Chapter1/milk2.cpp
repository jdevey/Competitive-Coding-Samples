/*
ID: deveyjo1
TASK: milk2
LANG: C++14            
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    
	freopen("milk2.in", "r", stdin);
	freopen("milk2.out", "w+", stdout);

	int* a = new int[1000001];
	memset(a, 0, sizeof(a));

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		++a[l];
		--a[r];
	}

	int mxOn = 0, mxOff = 0, pt, run = 0, firstMilk = 1000000, finalMilk = 0;

	for (int i = 0; i <= 1000000; ++i) {
		if (a[i]) {
			finalMilk = i;
			firstMilk = min(firstMilk, i);
		}
	}

	bool prevOn = true;
	pt = firstMilk;

	for (int i = firstMilk; i <= finalMilk + 1; ++i) {
		run += a[i];
		bool currOn = run;
		if (currOn != prevOn) {
			if (prevOn) {
				mxOn = max(mxOn, i - pt);
			}
			else {
				mxOff = max(mxOff, i - pt);
			}
			pt = i;
			prevOn = currOn;
		}
	}

	cout << mxOn << " " << mxOff << endl;

    return 0;
}
