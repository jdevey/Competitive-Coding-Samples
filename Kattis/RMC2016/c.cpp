#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int main() {

	int n;
	cin >> n;
	vector <ld> v;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		ld a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end(), std::greater<>());

	//for (auto x : v) cout << x << endl;
	
	cout.precision(4);

	ld sm = 0;
	for (int i = 1; i <= v.size(); ++i) sm += i * v[i - 1];

	cout << fixed << sm << endl;

	return 0;
}
