/*
ID: deveyjo1
TASK: gift1
LANG: C++14            
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    
	freopen("gift1.in", "r", stdin);
	freopen("gift1.out", "w+", stdout);

	int np;
	cin >> np;

	vector <string> vs;

	for (int i = 0; i < np; ++i) {
		string s;
		cin >> s;
		vs.push_back(s);
	}

	map <string, pair <int, int>> m;

	for (int i = 0; i < np; ++i) {
		string person;
		int gift, pCount;
		cin >> person >> gift >> pCount;
		m[person].second = gift;
		if (pCount == 0) {
			m[person].first += gift;
			continue;
		}
		for (int j = 0; j < pCount; ++j) {
			string s;
			cin >> s;
			m[s].first += gift / pCount;
		}
		m[person].first += gift % pCount;
	}

	for (auto x : vs) {
		cout << x << " " << m[x].first - m[x].second << endl;
	}

    return 0;
}
