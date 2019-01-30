#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

int main() {

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		string a[n];
		for (int i = 0; i < n; ++i) cin >> a[i];

		int rc[n] = {}, cc[m] = {};
		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
			if (a[i][j] == '1') {++rc[i]; ++cc[j];}
		}
		bool good = true;
		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
			if (a[i][j] == '0' && rc[i] && cc[j]) {
				good = false;
			}
		}
		if (!good) {
			cout << "impossible\n";
			for (int i = 0; i < 10; ++i) cout << '-';
				cout << endl;
			continue;
		}
		char build[n][m];
		int rdim = 0, cdim = 0;
		for (int i = 0; i < n; ++i) if (rc[i]) ++rdim;
		for (int i = 0; i < m; ++i) if (cc[i]) ++cdim;

		bool useI = rdim > 1 && cdim > 1;
		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
			build[i][j] = a[i][j] == '0' ? 'N' : (useI ? 'I' : 'P');
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) cout << build[i][j];
			cout << endl;
		}
		for (int i = 0; i < 10; ++i) cout << '-';
		cout << endl;
	}

	return 0;
}
