#include <bits/stdc++.h>

using namespace std;

bool isLet(char c) {
	return c >= 'a' && c <= 'z';
}

int main() {

	int n;
	cin >> n;

	vector <pair<int, string>> v;

	for (int i = 0; i < n; ++i) {
		string s1, s2;
		cin >> s1 >> s2;
		if (isLet(s1[0])) {
			v.push_back({stoi(s2), s1});
		}
		else v.push_back({stoi(s1) / 2, s2});
	}

	sort(v.begin(), v.end());

	for (auto x : v) cout << x.second << endl;

	return 0;
}
