/*
ID: deveyjo1
TASK: combo
LANG: C++14            
*/
#include <bits/stdc++.h>

using namespace std;

bool isRange(vector <int> combo, int* arr, int n) {
	for (int i = 0; i < 3; ++i) {
		for (int j = -2; j <= 2; ++j) {
			if (arr[i] == (combo[i] + j + n) % n) break;
			if (j == 2) return false;
		}
	}
	return true;
}

int main() {
    
	freopen("combo.in", "r", stdin);
	freopen("combo.out", "w+", stdout);

	int n, cnt = 0;
	cin >> n;
	int a[3], b[3];
	for (int i = 0; i < 3; ++i) cin >> a[i], --a[i];
	for (int i = 0; i < 3; ++i) cin >> b[i], --b[i];

	for (int i = 0; i < n * n * n; ++i) {
		vector <int> combo = {i / n / n, i / n % n, i % n};
		if (isRange(combo, a, n) | isRange(combo, b, n)) ++cnt;
	}

	cout << cnt << endl;

    return 0;
}
