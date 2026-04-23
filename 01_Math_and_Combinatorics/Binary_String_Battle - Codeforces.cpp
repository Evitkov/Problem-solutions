/*
* PROBLEM: Binary String Battle
 *
 * PROBLEM DESCRIPTION:
 * Alice and Bob take turns playing with a binary string of length n. Alice can turn
 * any subsequence of length k into 0s, and Bob can turn any contiguous substring of
 * length k into 1s. Alice wants all 0s, Bob wants at least one 1.
 *
 * SOLUTION DESCRIPTION:
 * A good quirk to remember for this exercise is that we only need to count the total 1s
 * and check two main math boundaries. Since k is at least 1, Alice wins immediately if
 * there are no 1s, or if she can just wipe out all the 1s on her very first turn because k >= num1.
 * If that doesnt happen she can still win if her reach covers more than half the
 * string (k * 2 > n) - that will always work since Bob has no way to place a contiguous
 * block of 1s without Alice's subsequence overlapping it and clearing it next turn.
 * Otherwise bob wins since we assume he didnt loose in the previous round -> he had at least 1 remaining ->
 * if k*2<=n the middle wont overlap and he can just choose one of the remaining 1s and dodge it by outputting new 1s
 * on the other side so even if alice plays optimally he can always dodge and so win.
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int num1 = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            num1++;
        }
    }

    if (k * 2 > n || k >= num1) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
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