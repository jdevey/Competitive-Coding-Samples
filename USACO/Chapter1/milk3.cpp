/*
ID: deveyjo1
TASK: milk3
LANG: C++14            
*/
#include <bits/stdc++.h>

using namespace std;

void dfs(set <vector <int>>& st, vector <int> trio, vector <int>& cap) {
	if (st.find(trio) != st.end()) return;
	st.insert(trio);
	dfs(st, {trio[0] - min(trio[0], cap[1] - trio[1]), trio[1] + min(trio[0], cap[1] - trio[1]), trio[2]}, cap);
	dfs(st, {trio[0] - min(trio[0], cap[2] - trio[2]), trio[1], trio[2] + min(trio[0], cap[2] - trio[2])}, cap);
	dfs(st, {trio[0] + min(trio[1], cap[0] - trio[0]), trio[1] - min(trio[1], cap[0] - trio[0]), trio[2]}, cap);
	dfs(st, {trio[0], trio[1] - min(trio[1], cap[2] - trio[2]), trio[2] + min(trio[1], cap[2] - trio[2])}, cap);
	dfs(st, {trio[0], trio[1] + min(trio[2], cap[1] - trio[1]), trio[2] - min(trio[2], cap[1] - trio[1])}, cap);
	dfs(st, {trio[0] + min(trio[2], cap[0] - trio[0]), trio[1], trio[2] - min(trio[2], cap[0] - trio[0])}, cap);
}

int main() {
    
	freopen("milk3.in", "r", stdin);
	freopen("milk3.out", "w+", stdout);

	vector <int> trio, cap(3);
	cin >> cap[0] >> cap[1] >> cap[2];
	trio = {0, 0, cap[2]};
	set <vector <int>> st;
	set <int> ft;
	dfs(st, trio, cap);
	for (auto x : st) if (!x[0]) ft.insert(x[2]);
	for (auto x : ft) {
		cout << x;
		if (x != *--ft.end()) cout << ' ';
	}
	cout << endl;

    return 0;
}
