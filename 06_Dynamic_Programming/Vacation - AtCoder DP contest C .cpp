/*
* PROBLEM: Vacation (AtCoder DP contest C)
 *
 * PROBLEM DESCRIPTION:
 * Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.
 * The vacation consists of N days. For each i (1 <= i <= N), Taro will choose one of
 * the following activities and do it on the i-th day:
 * * A: Swim in the sea. Gain a_i points of happiness.
 * B: Catch bugs in the mountains. Gain b_i points of happiness.
 * C: Do homework at home. Gain c_i points of happiness.
 * * As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.
 * Find the maximum possible total points of happiness that Taro gains.

 * SOLUTION DESCRIPTION:
 * This is introduction to 2D dp for me. Because we never know if our previous step lead to the highest result - usually in 1D
 * dp we just keep array of the best possible case until our step i. Here we can only keep the best possible case until the step i for each
 * different activity we decide to pick on day i. This introduces another dimension 0,1,2 depending on the activity we did on this day.
 * The best score on this day is then this activity plus the points we accumulated so far in the arrays for the other two activities.
 * In the end we get pick the maximum value of the sum of all happiness from the three options - we did activity a,b or c on the last day.

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
    int n;
    cin >> n;
    if (n==0) {
        cout<<"0"<<endl;
        return;
    }
    vi a(n);
    vi b(n);
    vi c(n);
    for (int i=0;i<n;i++) {
        cin>>a[i]>>b[i]>>c[i];
    }



    vector<vector<ll>> dp(n, vector<ll>(3));
    dp[0][0]=a[0];
    dp[0][1]=b[0];
    dp[0][2]=c[0];
    for (int i=1;i<n;i++) {
        dp[i][0]= max(dp[i-1][1]+a[i],dp[i-1][2]+a[i]);
        dp[i][1]= max(dp[i-1][0]+b[i],dp[i-1][2]+b[i]);
        dp[i][2]= max(dp[i-1][1]+c[i],dp[i-1][0]+c[i]);
    }
    cout<<max(dp[n-1][2],max(dp[n-1][0],dp[n-1][1]))<<endl;








}






int main() {
    fast_io();


    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}