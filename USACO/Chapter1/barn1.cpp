/*
ID: deveyjo1
TASK: barn1
LANG: C++14            
*/
#include <bits/stdc++.h>

using namespace std;

int findStart(bool* a, int s) {
	for (int i = 0; i < s; ++i) if (a[i]) return i;
}

int findEnd(bool* a, int s) {
	for (int i = s - 1; i > -1; --i) if (a[i]) return i;
}

int main() {
    
	freopen("barn1.in", "r", stdin);
	freopen("barn1.out", "w+", stdout);

	int m, s, c, occ;
	cin >> m >> s >> c;
	bool a[s] = {};
	for (int i = 0; i < c; ++i) {
		cin >> occ;
		a[occ - 1] = true;
	}

	int start = findStart(a, s), end = findEnd(a, s);

	int total = end - start + 1;

	vector <int> spaces;

	int ind = start;
	bool isOn = a[start];
	for (int i = start; i <= end; ++i) {
		if (i == end || a[i] != isOn) {
			if (!isOn) spaces.push_back(i - ind);
			ind = i;
			isOn = !isOn;
		}
	}

	sort(spaces.begin(), spaces.end());

	for (int i = 0; i < m - 1; ++i) {
		if (!spaces.empty()) {
			total -= spaces.back();
			spaces.pop_back();
		}
	}

	cout << total << endl;

    return 0;
}
