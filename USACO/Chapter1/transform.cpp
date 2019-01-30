/*
ID: deveyjo1
TASK: transform
LANG: C++14            
*/
#include <bits/stdc++.h>

using namespace std;

string a[10], b[10];
int n;

bool cmp() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[i][j] != b[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void rotate() {
	int temp[n][n];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			temp[i][j] = a[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			a[j][n - i - 1] = temp[i][j];
		}
	}
}

void flip() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n >> 1; ++j) {
			swap(a[i][j], a[i][n - j - 1]);
		}
	}
}

int main() {

	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w+", stdout);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	for (int i = 1; i <= 3; ++i) {
		rotate();
		if (cmp()) {
			cout << i << endl;
			return 0;
		}
	}

	rotate();

	flip();
	if (cmp()) {
		cout << 4 << endl;
		return 0;
	}

	for (int i = 1; i <= 3; ++i) {
		rotate();
		if (cmp()) {
			cout << 5 << endl;
			return 0;
		}
	}

	rotate();
	flip();

	if (cmp()) {
		cout << 6 << endl;
		return 0;
	}

	cout << 7 << endl;

	return 0;
}
