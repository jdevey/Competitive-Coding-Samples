#include <bits/stdc++.h>

using namespace std;

bool isPowTwo(int n) {
	int b = 2;
	while (b < n) b <<= 1;
	return b == n;
}

bool isGood(vector <int>& v, int base) {
	if (!isPowTwo(accumulate(v.begin(), v.end(), 0))) return false;
	for (auto x : v) if (x > base) return false;
	return true;
}

int findStart(vector <int>& v, int end, int base) {
	for (int i = end + 1; i < v.size(); ++i) {
		if (v[i] <= base) return i;
	}
	return v.size();
}

pair <int, int> findEndSum(vector <int>& v, int start, int base) {
	int end = start, sm = 0;
	for (int i = start; i < v.size() && v[i] <= base; ++i) {
		end = i;
		sm += v[i];
	}
	return {end, sm};
}

void custominsert(vector <int>& v, int pos, int desired) {
	if (desired > 8) {
		for (int i = 0; i < desired / 8; ++i) v.insert(v.begin() + pos, 8);
	}
	else v.insert(v.begin() + pos, desired);
}

int main() {

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		vector <int> v;
		for (char c : s) v.push_back(c - '0');

		int base = 2;
		while (!isGood(v, base)) {
			vector <tuple <int, int, int>> vt;
			int start = 0, end = -1, sm = 0;

			while (true) {
				start = findStart(v, end, base);
				//cout << start << endl;
				if (start == v.size()) break;
				tie(end, sm) = findEndSum(v, start, base);
				vt.push_back(make_tuple(start, end, sm));
				sm = 0;
			}/*
			for (auto x : vt) {
				cout << base << " " << get <0>(x) << " " << get <1>(x) << " " << get <2>(x) << endl;
			}*/
			for (int i = vt.size() - 1; i > -1; --i) {
				int target = base * 2;
				if (get <2>(vt[i]) % target == 0) continue;
				custominsert(v, get <1>(vt[i]) + 1, base);
			}

			//for (auto x : v) cout << x << " ";
			//cout << endl;
			
			base <<= 1;
		}

		for (auto x : v) cout << x;
		cout << endl;
	}

	return 0;
}
