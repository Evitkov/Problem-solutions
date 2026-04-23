/*
 * PROBLEM: Apple Division (CSES)
 *
 * PROBLEM DESCRIPTION:
 * There are n apples with known weights. Your task is to divide the apples into
 * two groups so that the difference between the weights of the groups is minimal.
 *
 * SOLUTION DESCRIPTION:
 * I initially thought to solve this problem using classic 2D dp knapsack but since value of each apple can be so high
 * and we would be simulating to half of this value in the worst case would have 20 times 10^10 array of longs which is
 * too large obviously.
 * * Since the maximum number of apples is very small we can solve this by brute-forcing every possible combination.
 *  For each apple, we have exactly two choices: we can either add it to Group 1,
 * or skip it . We use a recursively take the minimum of those two options.
 * We keep the sum of the weight of Group 1 and once we have made a decision for every apple  we can instantly find the weight of Group 2
 * by subtracting `weight1` from the pre-calculated `total_weight`. We then calculate
 * the absolute difference between the two groups.
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

//global vars
int n;
vector<ll> apple_weights;
ll total_weight = 0;

ll find_min_difference(int current_apple, ll weight1) {

    if (current_apple == n) {
        ll weight2 = total_weight - weight1;

        return abs(weight1 - weight2);
    }

    ll add = find_min_difference(current_apple + 1, weight1 + apple_weights[current_apple]);

    ll skip = find_min_difference(current_apple + 1, weight1);

    return min(add, skip);
}

void solve() {
    cin >> n;
    apple_weights.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> apple_weights[i];
        total_weight += apple_weights[i];
    }

    cout << find_min_difference(0, 0) << '\n';
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