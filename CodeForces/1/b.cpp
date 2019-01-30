#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

bool isFirst(string s) {
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] == 'C' && s[i - 1] >= '0' && s[i - 1] <= '9') return true;
	}
	return false;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n;
	cin >> n;

	while (n--) {
		string s;
		cin >> s;

		if (isFirst(s)) {
			int endPos = s.find('C');
			string sn, en;
			for (int i = 1; i < endPos; ++i) {
				sn += s[i];
			}
			for (int i = endPos + 1; i < s.size(); ++i) {
				en += s[i];
			}
			int colNum = stoi(en);

			string letPortion;

			while (colNum) {
				int num = colNum % 26;
				if (num == 0) {num = 26; colNum--;}
				letPortion = (char)(64 + num) + letPortion;
				colNum /= 26;
			}

			cout << letPortion << sn << endl;
		}
		else {
			int endPos = 1;
			for (int i = 0; i < s.size(); ++i) if (s[i] >= '0' && s[i] <= '9') {endPos = i; break;}

			string sn, en;
			for (int i = 0; i < endPos; ++i) sn += s[i];
			for (int i = endPos; i < s.size(); ++i) en += s[i];

			int num = 0;
			for (int i = 0; i < sn.size(); ++i) {
				num += (sn[i] - 64) * pow(26, sn.size() - i - 1);
			}

			cout << 'R' << en << 'C' << num << endl;
		}
	}

    return 0;
}
