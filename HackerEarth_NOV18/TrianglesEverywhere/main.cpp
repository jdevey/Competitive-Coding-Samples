#pragma GCC optimize("03")
 
#include <iostream>
#include <fstream>
#include <vector>
 
#define ll long long
 
#define BIGPRIME 1000000007
 
using namespace std;
 
int main() {

    vector<ll> answers;
 
    ll runningProd = 1;
    answers.push_back(1);
 
    for (int i = 1; i <= 1000000; ++i) {
        runningProd *= 3;
        ++runningProd;
        runningProd %= BIGPRIME;
        answers.push_back(runningProd);
    }
 
    vector <ll> answers2;
    answers2.push_back(1);
    for (int i = 1; i <= 1000000; ++i) {
        answers2.push_back((answers[i] + answers[i - 1]) % BIGPRIME);
    }
 
    ll q, n;
 
    cin >> q;
 
    while (q--) {
        cin >> n;
        cout << answers2[n] << endl;
    }
 
    return 0;
}
