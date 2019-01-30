/*
ID: deveyjo1
TASK: dualpal
LANG: C++14            
*/
#include <bits/stdc++.h>

using namespace std;

bool isPal(string s) {
	for (int i = 0; i < s.size(); ++i) if (s[i] != s[s.size() - i - 1]) return false;
	return true;
}

string baseB(int num, int b) {
	string ans;
	while (num) {
		ans = (num % b > 9 ? char(55 + num % b) : char(48 + num % b)) + ans;
		num /= b;
	}
	return ans;
}

int main() {
    
	freopen("dualpal.in", "r", stdin);
	freopen("dualpal.out", "w+", stdout);

	int n, s, mCount = 0;
	cin >> n >> s;

	for (int i = s + 1; mCount < n; ++i) {
		int pCount = 0;
		for (int b = 2; b <= 10; ++b) if (isPal(baseB(i, b))) ++pCount;
		if (pCount > 1) {
			++mCount;
			cout << i << endl;
		}
	}

    return 0;
}
