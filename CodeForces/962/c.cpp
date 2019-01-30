#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

vector <int> squares;

void init() {
	fl (i, 1, 44722) squares.push_back(i * i);
}

int numDig(int n) {
	int cnt = 1;
	while (n) {
		n /= 10;
		++cnt;
	}
	return cnt;
}

bool isGood(string sculpt, string block) {
	int p = 0;
	fl (i, 0, block.size()) {
		if (block[i] == sculpt[p]) ++p;
		if (p == sculpt.size()) return true;
	}
	return false;
}

int good(int ind, int n) {
	if (isGood(to_string(squares[ind]), to_string(n))) return numDig(n) - numDig(squares[ind]);
	return -1;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	init();

	int n;
	cin >> n;

	for (int i = squares.size() - 1; i > -1; --i) if (good(i, n) != -1) {
		cout << good(i, n) << endl;
		return 0;
	}

    return puts("-1");
}
