#include <bits/stdc++.h>
#define fl(i, m, n) for (int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;
typedef long double ld;

void makePFac(vector <int>* pList, int n) {
	for (int i = 1; i < n; ++i) for (int j = i; j < n; j += i) pList[j].push_back(i);
}

int main() {

	int n;
	cin >> n;

	vector <int>* pList = new vector<int>[n + 1]();

	makePFac(pList, n + 1);
	for (int i = 0; i < n + 1; ++i) sort(pList[i].begin(), pList[i].end());
	ll sm = 0;
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j < pList[i].size() - 1 && pList[i][j] < i; ++j) {
			sm += (ll)i / pList[i][j] * 4;
		}
	}

	cout << sm << endl;

    return 0;
}
