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

	int n, m;
	cin >> n >> m;

	vector <pair <string, string>> vv;
	vector <pair <string, string>> vx;
	fl (i, 0, n) {
		string s1, s2;
		cin >> s1 >> s2;
		vv.push_back(make_pair(s1, s2));
	}
	fl (i, 0, m) {
		string s1, s2;
		cin >> s1 >> s2;
		s2.pop_back();
		vx.push_back(make_pair(s1, s2));
	}

	fl (i, 0, m) {
		string s;
		fl (j, 0, n) {
			//cout << vx[i].second << " " << vv[j].second << endl;
			if (vx[i].second == vv[j].second) s = vv[j].first;
		}
		cout << vx[i].first << " " << vx[i].second << "; #" << s << endl;
	}

    return 0;
}
