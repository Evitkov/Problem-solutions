/*
* PROBLEM: Trailing Zeroes (CSES)
 *
 * PROBLEM DESCRIPTION:
 * Your task is to calculate the number of trailing zeros in the factorial n!.
 * For example, 20!=2432902008176640000 and it has 4 trailing zeros.
 *
 * SOLUTION DESCRIPTION:
 * Here we can sput that the fives are creating trailing zeros in combination with even numbers.
 * Since there is a lot of even number we can just count the number of fives.
 * Important thing to realize is that powers of five contribute i fives for pow =5^i.
 * We can just check for this by dividing by each power of 5 until that power is bigger thank k itself;
 *
 *

 */

#include <bits/stdc++.h> // Includes every standard library (Vector, Set, Map, Algorithm, etc.)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void solve() {
    ll k;
    cin>>k;
    ll counter =0;
    ll pow = 5;

    while (pow <= k) {
        counter += k / pow;

        if (k / 5 < pow) break;
        pow *= 5;
    }
    cout<<counter<<endl;
}


int main() {
    fast_io();

    int t = 1;

    // cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}