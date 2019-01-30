#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int zerCase(string s) {
	int fp = s.find('0'), score = 0;
	if (fp == string::npos) return 1e9;
	s.erase(s.begin() + fp);
	score += fp;
	fp = s.find('0');
	if (fp == string::npos) return 1e9;
	return score + fp;
}

int fCase(string s) {
	int fp = s.find('0'), score = 0;
	if (fp == string::npos) return 1e9;

	while (s[0] != '0') {
		swap(s[s.find('0')], s[s.find('0') - 1]);
		++score;
	}

	fp = s.find('5');
	if (fp != s.size() - 1) return score + fp - 1;
	int fc = 0;
	for (int i = s.size() - 2; i > -1 && s[i] == '0'; --i) {
		
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	string s;
	cin >> s;

	if (s.size() == 1) return puts("-1");

	reverse(s.begin(), s.end());

	int mn = 1e9, score = 0;

	mn = min(mn, zerCase);

    return 0;
}
