#include <iostream>
#include <fstream>
#include <vector>
 
#define ll long long
#define BIGPRIME 1000000007
 
using namespace std;
 
int main() {
 
    //ifstream cin("zin.txt");
 
    int t;
 
    cin >> t;
 
    ll n, m, k;
 
    while (t--) {
 
        cin >> n >> m >> k;
 
        //ll mm[i] = 0;
        vector <ll> a ((unsigned)m + 1, 0);
        a[0] = 1;
        a[1] = 2;
        vector <ll> mm ((unsigned)m + 1, 0);
        mm[0] = 0;
        mm[1] = 0;
 
        ll runningFac = 1;
        ll digRun = 0;
        ll twoBefore = 1;
        ll digTwo = 0;
        ll oneBefore = 1;
        ll digOne = 0;
        for (int i = 2; i <= m; ++i) {
 
            //Fibonacci
            a[i] = twoBefore + oneBefore;
            mm[i] = digOne + digTwo;
            if (a[i] >= BIGPRIME) {ll over = a[i] / BIGPRIME; mm[i] += over; mm[i] %= k; a[i] %= BIGPRIME;}
            if (mm[i] >= k) mm[i] %= k;
            twoBefore = oneBefore;
            oneBefore = a[i];
            digTwo = digOne;
            digOne = mm[i];
 
            if (i == 5 && t == 3) {
                cout << "";
            }
 
            //Factorial
            runningFac *= i;
            digRun *= i;
            if (runningFac >= BIGPRIME) {
                ll over = runningFac / BIGPRIME; digRun += over;  digRun %= k; runningFac %= BIGPRIME;
            }
            if (digRun >= k) digRun %= k;
 
            /*This is like doing two-digit by two-digit multiplication on paper.
            First we multiply the tens place, then the tens by the ones, then the ones by the tens,
             then the ones by the ones. Then we add them all up.
 
             In this case, runningFac and a[i] are the ones.
             */
 
            if (i == 5 && t == 3) {
                cout << "";
            }
 
            //Actually multiplying the factorial with the current value
            //F x A
            ll mTemp;
            if (digRun != 0) {
                mTemp = digRun * BIGPRIME;
                mTemp %= k;
                mTemp = mm[i] * mTemp;
            }
 
            //F x a
            ll aTemp = a[i] * digRun;
            if (aTemp >= k) aTemp %= k;
            //ll aTempComp = 0;
            //if (a[i] >= BIGPRIME) {ll over = a[i] / BIGPRIME; aTempComp += over;  aTempComp %= k; a[i] %= BIGPRIME;}
 
            //f x a
            a[i] *= runningFac;
 
            // f x A
            mm[i] *= runningFac;
            if (mm[i] >= k) mm[i] %= k;
 
            //Adding it all up after multiplying
            if (digRun != 0) {
                mm[i] += mTemp;
            }
            if (mm[i] >= k) mm[i] %= k;
            mm[i] += aTemp;
            if (mm[i] >= k) mm[i] %= k;
            if (a[i] >= BIGPRIME) {ll over = a[i] / BIGPRIME; mm[i] += over;  mm[i] %= k; a[i] %= BIGPRIME;}
 
            //Adding the previous a[i] and mm[i]
            a[i] += a[i - 1];
            mm[i] += mm[i - 1];
            if (a[i] >= BIGPRIME) {ll over = a[i] / BIGPRIME; mm[i] += over;  mm[i] %= k; a[i] %= BIGPRIME;}
            if (mm[i] > k) mm[i] %= k;
        }
 
        ll topValue = a[m];
        ll topDig = mm[m];
        topValue += topDig * BIGPRIME;
        ll botValue = a[n - 1];
        ll botDig = mm[n - 1];
        botValue += botDig * BIGPRIME;
        ll finalCount = topValue - botValue;
        finalCount += BIGPRIME * k;
 
        //mm[i] %= k;
        //ll multTemp = bigMod(max(finalCount, mm[i] * k), min(finalCount, mm[i] * k), k * BIGPRIME);
        //finalCount += multTemp;
        finalCount /= k;
 
        cout << finalCount % BIGPRIME << endl;
    }
 
    return 0;
}
