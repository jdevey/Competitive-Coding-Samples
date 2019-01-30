#include <bits/stdc++.h>

using namespace std;

bool comp(const vector <int>& a, const vector <int>& b) {
	return a.size() < b.size();
}

int main() {

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];

	bool choices[n] = {};
	int counts[2] = {};
	vector <int> cs[101] = {};
	for (int i = 0; i < n; ++i) cs[a[i]].push_back(i);

	vector <vector <int>> v;
	for (int i = 0; i < 101; ++i) if (cs[i].size()) v.push_back(cs[i]);

	sort(v.begin(), v.end(), comp);

	for (auto x : v) {
		if (counts[0] <= counts[1]) {
			if (x.size() == 1) {
				++counts[0];
				choices[x[0]] = false;
			}
			else if (x.size() == 2) {
				for (auto w : x) choices[w] = false;
			}
			else {
				if (counts[0] == counts[1]) continue;
				else if (counts[0] < counts[1]) {
					++counts[0];
					choices[x[0]] = false;
					for (int i = 1; i < x.size(); ++i) choices[x[i]] = true;
				}
			}
		}
		else {
			if (x.size() == 1) {
				++counts[1];
				choices[x[0]] = true;
			}
			else if (x.size() == 2) {
				for (auto w : x) choices[w] = true;
			}
			else {
				++counts[1];
				choices[x[0]] = true;
				for (int i = 1; i < x.size(); ++i) choices[x[i]] = false;
			}
		}
	}

	if (counts[0] != counts[1]) return puts("NO");
	else {
		cout << "YES" << endl;
		for (int i = 0; i < n; ++i) cout << (choices[i] ? "A" : "B");
	}

	return 0;
}
