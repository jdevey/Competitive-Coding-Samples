#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))
using namespace std;
typedef long long ll;
typedef long double ld;

int maxInc(string& s, int ind) {
    int i = ind;
    while (i < s.size() && s[i] == 'G') ++i;
    return i - ind;
}

int maxDec(string& s, int ind) {
    int i = ind;
    while (i > -1 && s[i] == 'G') --i;
    return ind - i;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	
	int n;
	cin >> n;
	string s;
	cin >> s;

	int mx = 0, segCount = 0;
	for (int i = 0; i < n - 1; ++i) {
	    if ((i == 0 || s[i] == 'S') && s[i + 1] == 'G') {mx = max(mx, maxInc(s, i ? i + 1 : 0)); ++segCount;}
	}

	if (segCount > 1) ++mx;

	for (int i = 1; i < n - 1; ++i) {
	    if (s[i - 1] == 'G' && s[i] == 'S' && s[i + 1] == 'G') {
	        mx = max(mx, maxInc(s, i + 1) + maxDec(s, i - 1) - (segCount == 2 ? 0 : -1));
	    }
	}

	cout << mx << endl;
	
    return 0;
}
