#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

bool isValid(string& start, string& model) {
	if (start.size() > model.size()) return false;
	int sz = start.size();
	fl (i, 0, sz) if (model[sz + i] != start[i]) return false;
	return true;
}

bool isTP(int n) {
	return __builtin_popcount(n) == 1;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	string s, ans;
	cin >> s;
	int ind = 0, cnt = 0;

	while (ind < s.size()) {
		if (isTP(ind) && isValid(ans, s)) {
			ind <<= 1;
			int sz = ans.size();
			fl (i, 0, sz) ans += ans[i];
		}
		else {
			ans += s[ind];
			ind++;
		}
		++cnt;
	}
	
	cout << cnt << endl;

    return 0;
}
