#include <bits/stdc++.h>
#include <unistd.h>

#define fl(i,a,b) for(int(i)=(a);(i)<(b);++i)

using namespace std;

int n;

struct Arr {
	int arr[8], depth;
	Arr(int* _arr, int _depth) {
		fl (i, 0, n) arr[i] = _arr[i];
		depth = _depth;
	}
	bool operator<(const Arr& rhs) const {
		fl (i, 0, n) if (arr[i] != rhs.arr[i]) return arr[i] < rhs.arr[i];
		return false;
	}
};

void reverse(int nn, int* a) {
	fl (i, 0, (nn >> 1) + 1) swap(a[i], a[nn - i]);
}

bool isPermute(int* a) {
	fl (i, 1, n + 1) if (a[i - 1] != i) return false;
	return true;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif
	
	cin >> n;
	int a[n];
	fl (i, 0, n) cin >> a[i];

	set <Arr> s;
	queue <Arr> q;

	Arr base(a, 0);
	q.push(base);
	s.insert(base);

	while (!q.empty()) {
		Arr curr = q.front();
		if (isPermute(curr.arr)) {
			cout << curr.depth << endl;
			return 0;
		}
		fl (i, 1, n) {
			reverse(i, curr.arr);
			Arr na(curr.arr, curr.depth + 1);
			if (s.find(na) == s.end()) {
				s.insert(na);
				q.push(na);
			}
			reverse(i, curr.arr);
		}
		q.pop();
	}

	return 0;
}
