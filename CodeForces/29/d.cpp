#include <bits/stdc++.h>

#define fl(i,m,n) for(int (i) = (m); (i) < (n); ++(i))

using namespace std;

typedef long long ll;

struct Node {
	int parent, vc;
	set <int> ch;
	Node() : vc(0) {}
};

void printVec(vector <int>& v) {
	for (auto x : v) cout << x << " ";
	cout << endl;
}

void dfs(Node* adj, vector <int>* ad, bool* vis, int currNode, int parent) {
	vis[currNode] = true;
	adj[currNode].parent = parent;
	for (auto x : ad[currNode]) {
		if (!vis[x]) {
			adj[currNode].ch.insert(x);
			dfs(adj, ad, vis, x, currNode);
		}
	}
}

int lca(Node* adj, int a, int b) {
	vector <int> v1, v2;
	while (true) {
		v1.push_back(a);
		if (adj[a].parent == -1) break;
		a = adj[a].parent;
	}
	while (true) {
		v2.push_back(b);
		if (adj[b].parent == -1) break;
		b = adj[b].parent;
	}
	reverse(v1.begin(), v1.end());
	reverse(v2.begin(), v2.end());
	//for (auto x : v1) cerr << "v1 " << x << " ";
	//for (auto x : v2) cerr << "v2 " << x << " ";

	for (int i = 0; i < v1.size(); ++i) {
		if (i == v1.size() || i == v2.size() || v1[i] != v2[i]) return v1[i - 1];
	}
	cerr << "shit\n";
	return -10;
}

vector <int> makePath(Node* adj, int lca, int start, int end) {
	vector <int> v1, v2;
	while (true) {
		if (start == lca) break;
		start = adj[start].parent;
		v1.push_back(start);
	}
	if (end == lca) return v1;
	while (true) {
		v2.push_back(end);
		end = adj[end].parent;
		if (end == lca) break;
	}
	reverse(v2.begin(), v2.end());
	if (lca == 4) {
		cerr << endl << "PATH" << endl;
		printVec(v1);
		printVec(v2);
	}
	v1.insert(v1.end(), v2.begin(), v2.end());
	return v1;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("zin.txt", "r", stdin);
#endif

	int n;
	cin >> n;

	Node adj[n + 1];
	adj[0].parent = -2;
	vector <int> ad[n + 1];
	fl (i, 0, n - 1) {
		int a1, a2;
		cin >> a1 >> a2;
		ad[a1].push_back(a2);
		ad[a2].push_back(a1);
	}

	bool vis[n + 1] = {};
	dfs(adj, ad, vis, 1, -1);

	vector <int> kk;
	int ki;
	while (cin >> ki) {
		kk.push_back(ki);
	}

	int currNode = kk[0];

	map <pair <int, int>, int> mp;
	vector <int> ans;
	++adj[1].vc;
	while (true) {
		ans.push_back(currNode);
		++adj[currNode].vc;
		currNode = adj[currNode].parent;
		if (currNode == 1) break;
	}
	ans.push_back(1);
	reverse(ans.begin(), ans.end());
	currNode = kk[0];
	printVec(ans);

	//for (auto x : kk) cerr << x << " ";
	for (int i = 1; i < kk.size(); ++i) {
		int lc = lca(adj, currNode, kk[i]);
		vector <int> path = makePath(adj, lc, currNode, kk[i]);
		printVec(path);
		for (auto x : path) {
			++adj[x].vc;
			ans.push_back(x);
		}
	}

	//for (auto x : adj) cerr << "x " << x.vc << endl;
	int lc = lca(adj, currNode, 1);
	//cerr << lc << " lc\n";
	vector <int> path = makePath(adj, lc, currNode, 1);
	for (auto x : path) {
		++adj[x].vc;
		ans.push_back(x);
	}

	for (auto x : adj) cerr << "x " << x.vc << endl;
	for (auto x : adj) if (x.parent != -2 && x.vc != x.ch.size() + 1) return puts("-1");

	for (auto x : ans) cout << x << " ";

	return 0;
}
