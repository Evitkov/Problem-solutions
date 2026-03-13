
/*
* PROBLEM: T-primes (CodeForces 230b)
 *
 * PROBLEM DESCRIPTION:
* We know that prime numbers are positive integers that have exactly two distinct positive divisors. Similarly, we'll call a positive integer t Т-prime, if t has exactly three distinct positive divisors.
*You are given an array of n positive integers. For each of them determine whether it is Т-prime or not.

*Input
*The first line contains a single positive integer, n  showing how many numbers are in the array.
*The next line contains n space-separated integers xi.
*
*
 * SOLUTION DESCRIPTION:
* This problem requires a lot of mathemathical knowledge. Firstly we use sieve of Eratosthenes to calculate all the primes until the
* square root of our input - since the vector is zero indexed 1000001 instead of 1000000. This precomputaion
* helps us with the time limit since we dont have to calculate this for each number in the array.
* Then in the method solve we see if the number has a whole square - since divisors wold always come in pairs
* and one pair si 1 and n itself we are looking just for one more divisor - this is only possible with square.
* Then we see if the root is prime. If it is then we use the fundemental theorem of algebra. Since every number has one unique sequence
* of prime divisors and our has sqrt(n) sqrt(n) we conclude those are the only divisors.
*
*
*
*/

#include <bits/stdc++.h> // Includes every standard library (Vector, Set, Map, Algorithm, etc.)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

vector<bool> is_prime(1000001, true);


void build_sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= 1000001; i++) {
        if (is_prime[i]) {

            // Invalidate all multiples of the prime

            for (int j = i+i; j < 1000001; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void solve() {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << "NO\n";
        return;
    }
    ll root = round(sqrt(n));
    if (root * root == n && is_prime[root] == true) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }


}


int main() {
    fast_io();
    build_sieve();

    int t = 1;

    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}}