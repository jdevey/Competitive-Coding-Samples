/*
ID: deveyjo1
TASK: beads
LANG: C++14            
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    
	freopen("beads.in", "r", stdin);
	freopen("beads.out", "w+", stdout);

	int n;
	cin >> n;
	string s;
	cin >> s;

	int mx = 0;

	for (int i = 0; i < n; ++i) {
		int pt1 = i, pt2 = (i + 1) % n, stop1 = (i + 1) % n, stop2 = i, cnt1 = 0, cnt2 = 0;
		char orig1 = s[i], orig2 = s[(i + 1) % n];
		do {
			if (s[pt1] != 'w' && orig1 == 'w') {
				orig1 = s[pt1];
			}
			if (s[pt1] == orig1 || s[pt1] == 'w') {
				++cnt1;
			}
			else {
				break;
			}
			pt1 = (pt1 - 1 + n) % n;
		} while (pt1 != stop1);
		do {
			if (s[pt2] != 'w' && orig2 == 'w') {
				orig2 = s[pt2];
			}
			if (s[pt2] == orig2 || s[pt2] == 'w') {
				++cnt2;
			}
			else {
				break;
			}
			pt2 = (pt2 + 1) % n;
		} while (pt2 != stop2);
		mx = max(mx, cnt1 + cnt2);
	}

	cout << min(mx, n) << endl;

    return 0;
}
