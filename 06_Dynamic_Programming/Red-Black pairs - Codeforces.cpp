/*
 * PROBLEM: Red-Black Pairs (Codeforces)
 *
 * PROBLEM DESCRIPTION:
 * You are given a 2 x n grid where each cell is colored either Red ('R') or Black ('B').
 * You need to partition all cells into n pairs such that the cells in each pair share
 * a side and have the same color. Find the minimum number of cells to repaint to
 * achieve this.
 *
 * SOLUTION DESCRIPTION:
 * Since there are 2 rows we know there are only 2 possible ways to fill one column either we fill it with one
 * vertical tile or two halves of 2 horizontal tiles - that will always be aligned the same since we know that
 * none of those 2 options allow filling only one of the tiles of column. This means we can just dynamically store the least amount
 * of recoloring we needed to do for our column.
 * We manually assign 1st and 2nd columns and then we have 2 options for each column util the end. Either we choose the minimum to get
 * to the previous one and add vertical tile or perhaps it was better to keep the previous tile horizontal so we get k-2 minimum
 * and add 2 horizontal tiles. The minimum of recoloring for one is then the minimum to get to this column. In the end
 * we just output min to get to the last column.
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
    int n;
    cin >> n;
    vector<char> a(n);
    vector<char> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vi dp(n);
    if (a[0]==b[0]) {
        dp[0] = 0;
    }else {
        dp[0] = 1;
    }
    int counter1=0;
    int counter2=0;
    if (a[1]==b[1]) {
        counter1 = 0;
    }else {
        counter1 = 1;
    }
    if (a[0]==a[1]) {
    }else {
        counter2 ++;

    }
    if (b[0]==b[1]) {

    }else {
        counter2 ++;
    }
    dp[1]= min(dp[0]+counter1,counter2);
    counter1 = 0;
    counter2 = 0;

    for (int i = 2; i < n; i++) {
        counter1 = 0;
        counter2 = 0;
        if (a[i]==b[i]) {
            counter1 = 0;
        }else {
            counter1 ++;
        }
        if (a[i-1]==a[i]) {
        }else {
            counter2 ++;

        }
        if (b[i-1]==b[i]) {

        }else {
            counter2 ++;
        }
        dp[i]  =min(dp[i-2]+counter2,dp[i-1]+counter1);

    }
    cout << dp[n-1] << endl;








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