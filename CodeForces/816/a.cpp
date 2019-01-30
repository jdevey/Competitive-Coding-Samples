#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

#ifndef ONLINE_JUDGE
	#define cin fin
	std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;

bool isPal(int h, int m) {
	return h % 10 == m / 10 && h / 10 == m % 10;
}

int main() {

	string s;
	cin >> s;
	string s1, s2;
	s1 += s[0]; s1 += s[1];
	s2 += s[3]; s2 += s[4];
	int h, m;
	string::size_type sz;
	h = stoi(s1, &sz);
	m = stoi(s2, &sz);

	int count = 0;
	while (!isPal(h, m)) {
		++m;
		if (m > 59) {
			m = 0;
			++h;
		}
		if (h > 23) {
			h = 0;
		}
		++count;
	}

	cout << count;

    return 0;
}
