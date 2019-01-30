#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

int main() {
	fl (i, 0, 10) {
		cout << i << endl << flush;
		string s;
		getline(cin, s);
		if (s == "don't think so" || s == "cool" || s == "great!" || s == "not bad" || s == "don't touch me!" || s == "no" && i > 2) return puts("normal");
		if (s == "terrible" || s == "worse" || s == "go die in a hole" || s == "are you serious?" || s == "don't even" || s == "no way") return puts("grumpy");
	}
}
