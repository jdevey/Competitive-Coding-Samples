/*
ID: deveyjo1
TASK: friday
LANG: C++14            
*/
#include <bits/stdc++.h>

using namespace std;

bool isLeap(int n) {
	if (n % 400 == 0) {
		return true;
	}
	if (n % 100 == 0) {
		return false;
	}
	if (n % 4 == 0) {
		return true;
	}
	return false;
}

void nextDay(int& year, int& month, int& day, int& dw) {
	dw = (dw + 1) % 7;
	++day;
	if (month == 1 && (isLeap(year) && day == 29 || !isLeap(year) && day == 28)) {
		month = 2;
		day = 0;
		return;
	}
	int ndpm[] = {31, 30, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (day == ndpm[month]) {
		day = 0;
		++month;
	}
	if (month == 12) {
		month = 0;
		++year;
	}
}

int main() {
    
	freopen("friday.in", "r", stdin);
	freopen("friday.out", "w+", stdout);
	
	int n;
	cin >> n;

	int dc[7] = {}, year = 1900, month = 0, day = 0, dw = 2;

	while (year < 1900 + n) {
		if (day == 12) ++dc[dw];
		nextDay(year, month, day, dw);
	}

	for (int i = 0; i < 6; ++i) {
		cout << dc[i] << " ";
	}
	cout << dc[6] << endl;

    return 0;
}
