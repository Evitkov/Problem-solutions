/*
    * PROBLEM: Knapsack 1 (AtCoder DP contest D)
     *
     * PROBLEM DESCRIPTION:
    * There are N items, numbered 1, 2, ..., N. For each i (1 <= i <= N),
    * Item i has a weight of w_i and a value of v_i.
    * Taro has decided to choose some of the N items and carry them home
    * in a knapsack. The capacity of the knapsack is W, which means that
    * the sum of the weights of items taken must be at most W.
    *  Find the maximum possible sum of the values of items that Taro takes home.
    *
     * SOLUTION DESCRIPTION:
     * This problem is one of the most common 2D dp patterns - we have items with weight and score -
     * how do we achieve the optimal score keeping the score below certain limit.
     *
     * The solution again uses one of the principles of dp - should i pick this item or no and saving the better option.
     * We use 2D array. In columns we have sizes 1 to w of hypothetical max sizes of
     * our container and in rows we have our items. Each entry then represents the best possibble
     * value we could get for a specific size container if we have available some items. First we start with
     * itarating through row one, since we created a row of 0 before we always assign this 0 and then check
     * if weight of our item is smaller or equal to maximal allowed weight for our column. If we can already insert our item since it is
     * the only one we will fill all our columns from some point on with it. For general item then we basically do the same just with a quirk.
    * We assign our cell the value of the cell above and then we again check if the weight of our new item is smaller than the weight allowed in our column.
    * This means from that point on in the row we have a choice to pick that item or no - meaning use the cell row above as previously assigned.
    * We get the best value for picking by looking at the cell w-weight of our item in the previous row and adding the value of our item. Why?
    * Because we need to be able to pick our item -> w - weight[i] and also this cell stores the best possible value for container of that size.
    * Then we just compare those two values and pick the higher one. In the end we just output bottom right of our grid - n -> grid with all items , w-> container with desired max size.
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
    int n, W;
    cin >> n >> W;

    vector<ll> weight(n + 1);
    vector<ll> value(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i];
    }


    vector<vector<ll>> dp(n + 1, vector<ll>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            dp[i][w]=dp[i - 1][w];
            if (w>=weight[i]) {
                ll taken = dp[i - 1][w-weight[i]]+value[i];
                dp[i][w]= max(dp[i][w], taken);
            }
        }
    }

    cout << dp[n][W] << "\n";
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