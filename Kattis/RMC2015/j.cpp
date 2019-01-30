#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
	int t, n;
	string city;
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		
		unordered_set<string> visited;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> city;
			visited.emplace(city);
		}
		cout << visited.size() << endl;
	}

	return 0;
}
