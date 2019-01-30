#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

void printVec(vector <string>& v) {
	for (auto x : v) cout << x << " ";
	cout << endl;
}

vector <string> san(string s) {
	vector <string> ret;
	size_t pos = 100;
	while (s.find("-") != string::npos) {
		pos = s.find_last_of("-");
		++pos;
		ret.push_back(s.substr(pos));
		s.resize(pos - 1);
	}
	ret.push_back(s);
	return ret;
}

int trans(string s) {
	if (s == "upper")
		return 0;
	else if (s == "middle")
		return 1;
	else if (s == "lower")
		return 2;
	else {
		cout << "FAILURE!!!!!!!!!" << endl;
		exit(0);
	}
}
/*
bool alpha(const string& s1, const string& s2) {
	size_t sz = min(s1.size(), s2.size());
	for (int i = 0; i < sz; ++i) {
		if (s1[i] < s2[i]) return true;
		else if (s1[i] > s2[i]) return false;
	}
	return s1.size() > s2.size();
}
*/
bool comp(const string& s1, const string& s2, const string& name1, const string& name2) {
	vector <string> v1 = san(s1), v2 = san(s2);
	//printVec(v1); printVec(v2);
	//reverse(v1.begin(), v1.end());
	//reverse(v2.begin(), v2.end());
	int sz = max(v1.size(), v2.size());
	for (int i = 0; i < sz; ++i) {
		int n1 = i >= v1.size() ? 1 : trans(v1[i]);
		int n2 = i >= v2.size() ? 1 : trans(v2[i]);
		if (n1 == n2) continue;
		return n1 < n2;
	}
	//cout << "match found " << s1 << " " << s2 << " " << name1 << " " << name2 << endl;
	//bool res = alpha(name1, name2);
	//cout << "vs " << s1 << " " << s2 << " " << res << endl;
	return name1 < name2;
}

struct Person {
	string name, cs;
	Person(string _name, string _cs) {
		name = _name;
		cs = _cs;
	}
	bool operator<(const Person& other) const {
		return comp(cs, other.cs, name, other.name);
	}
};

int main() {

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <Person> a;
		for (int i = 0; i < n; ++i) {
			string name, cs, garbage;
			cin >> name >> cs >> garbage;
			name.pop_back();
			a.push_back(Person(name, cs));
		}
		sort(a.begin(), a.end());
		for (int i = 0; i < n; ++i) cout << a[i].name << endl;
		for (int i = 0; i < 30; ++i) cout << '=';
		cout << endl;
	}

	//cout << comp("upper", "upper", "mom", "dad") << endl;

	return 0;
}
