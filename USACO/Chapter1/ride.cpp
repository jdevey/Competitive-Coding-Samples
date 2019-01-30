/*
ID: deveyjo1
TASK: ride
LANG: C++14            
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    
	freopen("ride.in", "r", stdin);
	freopen("ride.out", "w+", stdout);

	string s1, s2;
	cin >> s1 >> s2;
	int prod1 = 1, prod2 = 1;

	for (auto x : s1) {
		prod1 *= x - 64;
	}
	for (auto x : s2) {
		prod2 *= x - 64;
	}

	cout << (prod1 % 47 == prod2 % 47 ? "GO" : "STAY") << endl;

    return 0;
}
