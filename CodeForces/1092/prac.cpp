#include <bits/stdc++>

using namespace std;

void tokenize(string& s, int k) {

	string ret;
	string letters;
	for (auto c : s) if (c != '-') letters += c;

	size_t sz = letters.size();

	int cnt = sz / k;
	int remainder = sz % k;

	for (int i = 0, x = sz - 1; i < cnt; ++i) {

		for (int j = 0; j < k; ++j) {
			
			--x;
		}
	}

}

int main() {

	int k;
	string s;
	cin >> s >> k;
	tokenize(s, k);
	cout << s << endl;

	return 0;
}
