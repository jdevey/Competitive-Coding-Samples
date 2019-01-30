#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;

struct Ing {
	string name;
	ld weight, perc;
};

int main() {

	int t;
	cin >> t;
	for (int u = 1; u <= t; ++u) {
		cout << "Recipe # " << u << endl;
		int n, a1, a2;
		cin >> n >> a1 >> a2;
		ld ratio = (ld)a2 / a1;
		Ing a[n];
		for (int i = 0; i < n; ++i) cin >> a[i].name >> a[i].weight >> a[i].perc;

		int mainInd = 0;
		for (int i = 0; i < n; ++i) if (a[i].perc == 100.0) mainInd = i;

		ld mainWeight = a[mainInd].weight * ratio;
		cout.precision(1);
		for (int i = 0; i < n; ++i) {
			cout << a[i].name << " ";
			if (i == mainInd) {
				cout << fixed << mainWeight << endl;
			}
			else {
				cout << fixed << a[i].perc * mainWeight / 100 << endl;
			}
		}
		for (int i = 0; i < 40; ++i) cout << "-";
		cout << endl;
	}

	return 0;
}
