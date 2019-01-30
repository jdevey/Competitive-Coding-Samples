#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))
/*
#ifndef ONLINE_JUDGE
#define cin fin
std::ifstream fin("zin.txt");
#endif
*/
using namespace std;

typedef long long ll;

bool isMatch(string s, string full) {
	if (s.size() > full.size()) return false;
	fl (i, 0, s.size()) if (s[i] != full[i]) return false;
	return true;
}

int main() {

	int n, q;
	cin >> n;

	map <string, int> memo;
	map <string, int> ss;
	fl (i, 0, n) {
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		++ss[s];
	}

	cin >> q;
	while (q--) {
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		if (memo.find(s) != memo.end()) {
			cout << memo.find(s)->second << endl;
			continue;
		}
		int cnt = 0;
		for (auto it = ss.lower_bound(s); it != ss.end() && isMatch(s, it->first); ++it) cnt += it->second;
		memo.insert(make_pair(s, cnt));
		cout << cnt << endl;
	}

	return 0;
}

