#include <bits/stdc++.h>

using namespace std;

bool collide(int pos1, int pos2) {
	return abs(pos1 - pos2) < 5;
}

int main() {

	int pos1, pos2;
	cin >> pos1 >> pos2;
	int n1, n2;
	cin >> n1;
	int a1[n1];
	for (int i = 0; i < n1; ++i) cin >> a1[i];
	cin >> n2;
	int a2[n2];
	for (int i = 0; i < n2; ++i) cin >> a2[i];

	bool* c1 = new bool[3000001];
	bool* c2 = new bool[3000001];
	memset(c1, 0, sizeof(c1));
	memset(c2, 0, sizeof(c2));

	for (int i = 0; i < n1; ++i) c1[a1[i]] = true;
	for (int i = 0; i < n2; ++i) c2[a2[i]] = true;

	bool v1 = false, v2 = false;
	for (int i = 0; i < 3000000; ++i) {
		if (collide(pos1, pos2)) {
			cout << "bumper tap at time " << i;
			return 0;
		}
		v1 = c1[i] ? !v1 : v1;
		v2 = c2[i] ? !v2 : v2;
		pos1 = v1 ? pos1 + 1 : pos1;
		pos2 = v2 ? pos2 + 1 : pos2;
		//cout << i << " " << pos1 << " " << pos2 << endl;
	}

	cout << "safe and sound";

	return 0;
}
