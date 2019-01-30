#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

#ifndef ONLINE_JUDGE
	#define cin fin
	std::ifstream fin("zin.txt");
#endif

using namespace std;

typedef long long ll;

int main() {

	string s1, s2;
	cin >> s1 >> s2;
	int n;
	cin >> n;
	cout << s1 << " " << s2 << endl;

	while (n--) {
		string a, b;
		cin >> a >> b;
		if (a == s1) {
			s1 = b;
		}
		else if (a == s2) {
			s2 = b;
		}
		else if (b == s1) {
			s1 = a;
		}
		else if (b == s2) {
			s1 = b;
		}
		cout << s1 << " " << s2 << endl;
	}

    return 0;
}
