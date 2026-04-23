/*
* PROBLEM: Digit Queries (CSES)
 *
 * PROBLEM DESCRIPTION:
 * Consider an infinite string that consists of all positive integers in increasing order:
 * 123456789101112131415161718192021...
 * Your task is to process q queries, where each query asks for the k-th digit in this string.
 *
 * SOLUTION DESCRIPTION:
 * This is easy problem to spot the pattern but again it was bit harder for me to get the correct implementation.
 * I initially tried to solve this by finding the nearest power of 10, but I got stuck because
 * my while loop was comparing the string position (k) directly to the actual number values.
 * In the correct solution we first find the length of the number / how many digits the number we are looking for has
 * This is done by the first while loop which substracts the number of digits reserved for each group - 10-99 - group of
 * 90 numbers of length 2 so -180 - with2 being the length and 90 count. Now we find the correct number by zero indexing
 * and dividing by length. Here i had bit of problems how to extract the correct digit because each will have a different
 * repeating pattern but this solution simplifies this nicely by converting this number getting the exact number as stated before
 * coverting to string and exctracting the digit by mod - my initial idea was kind of formalize the pattern for each digit and use mod
 * to find the digit but this was too complicated.
 *
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void solve() {
    ll k;
    cin >> k;

    ll length = 1;
    ll count = 9;
    ll start = 1;

    while (k > length * count) {
        k -= length * count;
        length++;
        count *= 10;
        start *= 10;
    }

    start += (k - 1) / length;

    string s = to_string(start);
    cout << s[(k - 1) % length] << endl;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}