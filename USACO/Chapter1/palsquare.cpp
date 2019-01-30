/*
ID: deveyjo1
TASK: palsquare
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
    
	freopen("palsquare.in", "r", stdin);
	freopen("palsquare.out", "w+", stdout);

	int b;
	cin >> b;

	for (int i = 1; i <= 300; ++i) if (isPal(baseB(i * i, b))) cout << baseB(i, b) << " " << baseB(i * i, b) << endl;

    return 0;
}
