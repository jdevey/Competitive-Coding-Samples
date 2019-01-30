/*
ID: deveyjo1
TASK: sprime
LANG: C++14            
*/
#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
	if (n < 2) return false;
	if (n == 2 || n == 3) return true;
	int sqt = sqrt(n);
	for (int i = 2; i <= sqt; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

void dfs(vector <int>& ans, int num, int& goal, int depth) {
	if (depth > goal) return;
	for (int i = num * 10; i < num * 10 + 10; ++i) {
		if (isPrime(i)) {
			if (depth == goal) ans.push_back(i);
			dfs(ans, i, goal, depth + 1);
		}
	}
}

int main() {

	freopen("sprime.in", "r", stdin);
	freopen("sprime.out", "w+", stdout);

	int n;
	cin >> n;
	vector <int> ans;
	dfs(ans, 0, n, 1);
	sort(ans.begin(), ans.end());
	for (auto x : ans) cout << x << endl;

	return 0;
}
