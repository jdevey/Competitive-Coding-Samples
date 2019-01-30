#include <bits/stdc++.h>

using namespace std;

int main() {

	int nn;
	cin >> nn;

	int n = 0, m = 0;
	string sss;

	for (int i = 0; i < nn; ++i) {
		cin >> sss >> sss;
		if (sss == "soft") ++n;
		else ++m;
	}

	int sz = max(n, m);
	if (sz & 1 && n != m) sz = sz * 2 - 1;
	else sz *= 2;

	cout << (int)sqrt(sz - 1) + 1 << endl;

	return 0;
}
