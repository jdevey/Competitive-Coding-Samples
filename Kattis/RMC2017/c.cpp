//TODO WA?

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void printMap(map <int, int>& m) {
	for (auto x : m) cout << x.first << " " << x.second << endl;
}

void erato(bool* a, int n) {
	for (int i = 2; i < n; ++i) {
		for (int j = a[i] ? n : 2 * i; j < n; j += i) {
			a[j] = true;
		}
	}
}

map <int, int> pFacs(vector <int>& pList, int n) {
	map <int, int> m;
	for (auto x : pList) {
		while (n % x == 0) {
			++m[x];
			n /= x;
		}
	}
	return m;
}

bool isPrime(vector <int>& pList, ll n) { 
	for (auto x : pList) {
		if (n % x == 0) return false;
		if (x == n || x >= sqrt(n) + 1) return true;
	}
}

bool iz(map <int, int>& m) {
	for (auto x : m) if (x.second) return false;
	return true;
}

int findMin(map <int, int>& m) {
	int mn = 1e9, ind;
	for (auto x : m) {
		if (x.second < mn) {
			mn = x.second;
			ind = x.first;
		}
	}
	return ind;
}

int findMax(map <int, int>& m) {
	int mx = -1, ind;
	for (auto x : m) {
		if (x.second > mx) {
			mx = x.second;
			ind = x.first;
		}
	}
	return ind;
}

int winner(map <int, int>& m, int sm) {
	bool odd = sm & 1;
	map <int, int> mm = m;
	bool first = true;
	while (true) {
		if (odd) {
			if (first) {
				--mm[findMax(mm)];
			}
			else {
				--mm[findMin(mm)];
			}
		}
		else {
			if (first) {
				--mm[findMin(mm)];
			}
			else {
				--mm[findMax(mm)];
			}
		}
		if (mm[findMin(mm)] < 0) return 0;
		if (iz(mm)) return odd ? 1 : -1;
		first = !first;
	}
}

int main() {

	map <int, int> tm = {{2, 2}, {5, 1}};
	//cout << findMax(tm) << endl;

	int MAX = 100000;
	bool sieve[MAX] = {};
	sieve[0] = true; sieve[1] = true;
	erato(sieve, MAX);
	vector <int> pList;
	for (int i = 0; i < MAX; ++i) if (!sieve[i]) pList.push_back(i);

	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		string name;
		cin >> name;

		if (isPrime(pList, n)) {
			cout << name << endl;
			continue;
		}

		map <int, int> fc = pFacs(pList, n);
		int sm = 0;
		for (auto x : fc) sm += x.second;
		string winStr = sm & 1 ? name : name == "Bob" ? "Alice" : "Bob", tieStr = "tie";

		int code = winner(fc, sm);
		cout << (code ? winStr : tieStr) << endl;
	}

	return 0;
}
