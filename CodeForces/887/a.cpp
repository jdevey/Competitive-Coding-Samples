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

int main() {

	string s;
	cin >> s;

	int sz = s.size();
	//cout << s.size() << endl;
	while (sz--) {
		//cout << s << endl;
		if (s[0] == '0') s.erase(s.begin(), s.begin()+1);
		else break;
	}

	int sCount = 0, oCount = 0;
	fl (i, 0, s.size()) {
		if (s[i] == '0') ++sCount;
		else ++oCount;
	}

	cout << ((sCount >= 6  && oCount != 0) ? "yes" : "no") << endl;

    return 0;
}
