/*
* PROBLEM: Grid 1 (AtCoder DP Contest H)
 *
 * PROBLEM STATEMENT:
 * There is a grid with H horizontal rows and W vertical columns. Let (i, j) denote the
 * square at the i-th row from the top and the j-th column from the left.
 * * For each i and j (1 <= i <= H, 1 <= j <= W), Square (i, j) is described by a character a_{i,j}.
 * If a_{i,j} is '.', Square (i, j) is an empty square.
 * If a_{i,j} is '#', Square (i, j) is a wall square.
 * It is guaranteed that Squares (1, 1) and (H, W) are empty squares.
 * * Taro will start from Square (1, 1) and reach (H, W) by repeatedly moving right or down
 * to an adjacent empty square.
 * * Find the number of Taro's paths from Square (1, 1) to (H, W). As the answer can be
 * extremely large, find the count modulo 10^9 + 7.
 *
* *
 * SOLUTION DESCRIPTION:
 * This problem wasnt too challenging but I decided to include it since it shows easy use case of
 * dp for finding number of paths. At the start we initialize array with all elements 0 except for our entry point.
 * Then we iteratate through grid and if we didnt find wall we store the number of ways we could get to the specific
 * cell by adding the number of paths going to the cell left and above. This problem again also showcases nice use of the
 * modulo operator. Since it removes exactly the value of the modulo even if this value stacked up through repeated additions
 * 5a%a = a%a = 0 so we can just take the modulo of teh result for the cells and still get to the correct result in the last cell which we output.

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
    int H, W;
    cin >> H >> W;

    vector<vector<char>> grid(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<ll>> dp(H+1, vector<ll>(W+1,0));
    dp[1][1] = 1;
    for (int i = 1; i <= H; i++) {

        for (int j = 1; j <= W; j++) {
            if (i==1&&j==1) {
                continue;
            }
            if (grid[i-1][j-1] == '#') dp[i][j] = 0;
            else {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%1000000007;
            }

        }
    }
    cout << dp[H][W] << endl;


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