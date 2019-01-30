#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

int a[1000][1000];

struct Node {
	int val, x, y;
	Node(int _val, int _x, int _y) {
		val = _val;
		x = _x;
		y = _y;
	}
	bool operator<(const Node& rhs) const {
		return val < rhs.val;
	}
};

bool isGood(vector <Node>& vn, int ind, int tot) {
	fl (i, ind + 1, tot) if (vn[ind].x != vn[i].x && vn[ind].y != vn[i].y && a[vn[ind].y][vn[i].x] >= vn[ind].val && a[vn[i].y][vn[ind].x] >= vn[ind].val) return true;
	return false;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n, m;
	scanf("%d %d", &n, &m);
	fl (i, 0, n) fl (j, 0, m) scanf("%d", &a[i][j]);

	vector <Node> vn;

	fl (i, 0, n) fl (j, 0, m) vn.push_back(Node(a[i][j], j, i));

	sort(vn.begin(), vn.end());

	//fl (i, 0, vn.size()) cout << vn[i].x << " " << vn[i].y << " " << vn[i].val << endl;

	int tot = n * m, ind = 0;

	for (int jump = tot; jump; jump >>= 1) {while (ind + jump < tot && isGood(vn, ind + jump, tot)) ind += jump; cout << ind << " " << jump << endl;}

	cout << vn[ind].x << " " << vn[ind].y << " " << vn[ind].val;

    return 0;
}
