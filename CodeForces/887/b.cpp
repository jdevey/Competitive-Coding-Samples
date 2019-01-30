#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

#ifndef ONLINE_JUDGE
	#define cin fin
	std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;

int main() {

	int n;
	cin >> n;
	int a[n][6];
	fl (i, 0, n) fl (j, 0, 6) cin >> a[i][j];

	vector <string> ss;
	bool bt[1000] = {};

	fl (i, 0, pow(7, n)) {
		string s;
		int num = i;
		fl (j, 0, n) {
			if (num % 7 != 6) s += to_string(a[j][num % 7]);
			num /= 7;
		}
		ss.push_back(s);
	}

	fl (i, 0, ss.size()) sort(ss[i].begin(), ss[i].end());
	fl (i, 0, ss.size()) {
		string s = ss[i];
		while (next_permutation(s.begin(), s.end())) ss.push_back(s);
	}
	
	sort(ss.begin(), ss.end());
	ss.erase(ss.begin(), ss.begin() + 1);
	string::size_type sz;

	fl (i, 0, ss.size()) if (ss[i][0] != '0') bt[stoi(ss[i], &sz)] = true;

	fl (i, 1, 1000) if (!bt[i]) {cout << max(0, i - 1); return 0;}

    return 0;
}
