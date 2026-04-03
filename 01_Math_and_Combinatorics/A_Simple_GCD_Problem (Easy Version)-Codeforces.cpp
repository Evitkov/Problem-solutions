/*
* PROBLEM: C1. A Simple GCD Problem (Easy Version) (Codeforces)
 *
 * PROBLEM DESCRIPTION:
 * We have an array 'a' of length 'n' and an array 'b' of the same length (in this easy
 * version, a_i = b_i for all i).
 * For each element a_i, we can optionally replace it with an integer m (1 <= m <= b_i,
 * and m != a_i). This operation can be done at most once per index.
 * The condition is that the Greatest Common Divisor (GCD) of every possible subarray of
 * length 2 or more must remain exactly the same as it was in the original array.
 * The goal is to determine the maximum number of operations (changes to elements) we
 * can perform while ensuring the GCD condition holds for all subarrays.
 *
 * SOLUTION DESCRIPTION:
 * Since bi is the same ai and we only look at smaller number this doesnt concern us since the divisor would be form 1 to n anyways.
 * We know we have to keep the gcd of all subarrays the same. We do not need to check all subarrays. Since gcd is associative if we
 * dont change gcd of i +1 for elements after i+1 we can say it also didnt change since gcd i i+1 i+2  = gcd ((i i+1)i+2) etc..
 * Then we also need to check for both the element before. After we do this we know we can at most reduce to number which contains both of these
 * as its divisors hence we find lcm(gcd1,gcd2). Then we only need to check if our number is bigger then this since this is the total minimal element we can reduce to.
 * If it is we just increment the counter which we output at the end.
 *
 * */
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
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }
    int counter = 0;
    for (int i= 0; i < n; i++) {
        if (i==0) {
            if (gcd(a[i],a[i+1])<a[i]) {
                counter++;
            }

        }
        else if (i==n-1) {
            if (gcd(a[i],a[i-1])<a[i]) {
                counter++;
            }
        }
        else {
            if (lcm(gcd(a[i],a[i+1]),gcd(a[i],a[i-1]))<a[i]) {
                counter++;
            }
        }

    }
    cout << counter << endl;

}

int main() {
    fast_io();

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}