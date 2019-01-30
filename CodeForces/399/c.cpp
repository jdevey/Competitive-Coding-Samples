#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

ll compScore(string s) {
	bool isA = s[0] == 'o';
	ll curr = 0;
	ll sum = 0;
	fl (i, 0, s.size()) {
		if (s[i] == 'o' == isA) ++curr;
		else {
			sum += (isA ? 1 : -1) * curr * curr;
			curr = 1;
			isA = !isA;
		}
	}
	sum += (isA ? 1 : -1) * curr * curr;
	return sum;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int a, b;
	cin >> a >> b;
	string s1, s2;

	int first = b >> 1;
	fl (i, 0, first) s1 += 'x';
	fl (i, 0, a) s1 += 'o';
	fl (i, 0, b - first) s1 += 'x';

	++a;
	int base1 = b / a, base2 = b / a + 1;
	int lowerMult = a - (b % a), upperMult = b % a;

	//cout << base1 << " " << base2 << " " << lowerMult << " " << upperMult << endl;

	fl (i, 0, lowerMult) {
		fl (j, 0, base1) s2 += 'x';
		s2 += 'o';
	}
	//cout << s << endl;
	fl (i, 0, upperMult) {
		fl (j, 0, base2) s2 += 'x';
		s2 += 'o';
	}
	s2.pop_back();

	ll score1 = compScore(s1), score2 = compScore(s2);

	if (score1 > score2) {
		cout << score1 << endl;
		cout << s1;
	}
	else {
		cout << score2 << endl;
		cout << s2;
	}

	return 0;
}
