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
	string rs = s;
	fl (i, 0, s.size()) rs += s[s.size() - i - 1];

	cout << rs;

    return 0;
}
