/*
 * PROBLEM: B. Mickey Mouse Constructive (Codeforces) - Div 1/2 B
 *
 * PROBLEM DESCRIPTION:
 * Given two integers x and y, representing x copies of the number 1 and y copies
 * of the number -1. Let f(a) be the number of ways to partition an array 'a' into
 * one or more contiguous subarrays such that each element appears in exactly one
 * subarray, and all subarrays have the exact same sum.
 * * Find the minimum value of f(a) over all possible arrays of length x + y.
 * Output this minimum value modulo 676767677, and then construct and output
 * one such array that achieves this minimum value.
 *
 * Constraints:
 * 1 <= t <= 10^4
 * 0 <= x, y <= 2 * 10^5
 * x + y >= 1
 *
* SOLUTION DESCRIPTION:
 * This problem is a really cool math and constructive puzzle. At first it looks like
 * we need to simulate partitions, but it actually just boils down to finding divisors.
 * First, we calculate the absolute total sum of the array. If we want to divide the array
 * into valid sub-partitions that all equal the same number, the amount of partitions we make
 * must be a divisor of this total sum. We find the divisors of the total using the standard sqrt method.
 * To force the absolute minimum number of partitions, we arrange the array by grouping all
 * the 1s together at the start, followed by all the -1s. This creates a "mountain" shape
 * in our prefix sums, the running total strictly goes up and then strictly comes down.
 * Because it never bounces up and down, the running sum hits the required sum for
 * any valid partition exactly once. It completely prevents any smaller partitions
 * from forming.
 * */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void solve() {
    int x, y;
    cin >> x >> y;

    ll total = abs(x - y);

    if (total == 0) {
        cout << 1 << "\n";
    } else {
        ll counter = 0;

        for (ll i = 1; i * i <= total; i++) {
            if (total % i == 0) {
                counter = (counter + 1) % 676767677;

                if (i * i != total) {
                    counter = (counter + 1) % 676767677;
                }
            }
        }
        cout << counter << "\n";
    }

    for (int i = 0; i < x; i++) {
        cout << 1 << " ";
    }
    for (int i = 0; i < y; i++) {
        cout << -1 << " ";
    }
    cout << "\n";
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