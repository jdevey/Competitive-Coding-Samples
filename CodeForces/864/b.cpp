#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

#ifndef ONLINE_JUDGE
	#define cin fin
	std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;

bool isCap(char c) {
	return c >= 'A' && c <= 'Z';
}

int main() {

	int n;
	string s;
	cin >> n >> s;

	int mx = 0;
	fl (i, 0, n) {
		set <char> m;
		fl (j, i, n) {
			if (isCap(s[j])) break;
			if (m.find(s[j]) == m.end()) m.insert(s[j]);
		}
		if (m.size() > mx) mx = m.size();
	}

	cout << mx;

    return 0;
}
