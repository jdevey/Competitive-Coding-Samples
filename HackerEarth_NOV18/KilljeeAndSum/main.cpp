#pragma GCC optimize("03")
 
#include <iostream>
#include <fstream>
#include <vector>
 
#define fl(x,n) for(int (x) = 0; (x) < (n); ++(x))
 
#define ll long long
#define BIGPRIME 10000019
 
using namespace std;
 
ll factorList[BIGPRIME + 1];
 
ll EE(ll a, ll b, ll xy[]) {
    if (b == 0) {
        xy[0] = 1;
        xy[1] = 0;
        return a;
    }
    else {
        ll d = EE(b, a % b, xy);
        ll temp = xy[0] - a / b * xy[1];
        xy[0] = xy[1];
        xy[1] = temp;
        return d;
    }
}
 
ll modInverse(ll a) {
    ll xy[2];
    EE(a, BIGPRIME, xy);
    return xy[0] < 0 ? xy[0] + BIGPRIME : xy[0];
}
 
ll nChooseK (ll n, ll k) {
    //Basic properties of binomials
    if (k < 0) return 0;
    if (k > n) return 0;
 
    //Exploring the modulo versions of n and k and their repurcussions
    ll postN = n % BIGPRIME;
    ll postK = k % BIGPRIME;
 
    //If postK is bigger than postN, that means that the range of factorials covered while calculating n choose k
    //includes BIGPRIME, meaning that the final answer must be zero. Note that this rule wouldn't be true if
    //BIGPRIME wasn't prime. Note that (postN - postK)! can do nothing to prevent this zero-outcome.
    if (postK > postN) return 0;
    if (postK == postN) return 1;
    if (postK == 0) return 1;
 
    return (factorList[postN] * modInverse(factorList[postN - postK])) % BIGPRIME * modInverse(factorList[postK]) % BIGPRIME;
}
 
int main() {

    factorList[0] = 1;
    for (int i = 1; i <= BIGPRIME; ++i){
        factorList[i] = factorList[i - 1] * i % BIGPRIME;
    }
 
    ll t, n, m, r;
 
    cin >> t;
 
    while (t--) {
        
        cin >> n >> m >> r;
 
        ll ans = ((n % BIGPRIME) * (m % BIGPRIME)) % BIGPRIME;
 
        ans *= nChooseK(n + m - 2, r - 2);
 
        cout << ans % BIGPRIME << endl;
    }
 
    return 0;
}
