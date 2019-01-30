/*
ID: deveyjo1
TASK: namenum
LANG: C++14            
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    
	freopen("namenum.in", "r", stdin);
	freopen("namenum.out", "w+", stdout);

	ifstream fin("dict.txt");

	map <char, set <char>> m = {
		{'2', {'A', 'B', 'C'}},
		{'3', {'D', 'E', 'F'}},
		{'4', {'G', 'H', 'I'}},
		{'5', {'J', 'K', 'L'}},
		{'6', {'M', 'N', 'O'}},
		{'7', {'P', 'R', 'S'}},
		{'8', {'T', 'U', 'V'}},
		{'9', {'W', 'X', 'Y'}}
	};

	string num, name;
	cin >> num;

	vector <string> ans;

	while (fin >> name) {
		if (name.size() != num.size()) continue;
		for (int i = 0; i < num.size(); ++i) {
			if (m[num[i]].find(name[i]) == m[num[i]].end()) break;
			if (i == num.size() - 1) ans.push_back(name);
		}
	}

	fin.close();

	if (ans.empty()) cout << "NONE" << endl;
	else for (auto x : ans) cout << x << endl;

    return 0;
}
