/*
* PROBLEM: Two Knights (CSES)
 *
 * PROBLEM DESCRIPTION:
 * Your task is to count for k=1,2,....n the number of ways two knights can be placed on a
 * k times k chessboard so that they do not attack each other.
 *
 * SOLUTION DESCRIPTION:
 * I tried to solve this problem by simulation but that is obviously not possible for large amouts of test cases and big ks.
 * The solution is taking the total number of combinations of 2 knights on the board which i correctly found as -
 * k^2*(k^2-1)/2 - this is just the sum formula for arithmetic series with k^2 elements first one being k^2-1 ways to put the 2nd knight on the board for the
 * first square and last one being 0. Then we substract the num ways they attack each other. This is where i gto stuck for a while.
 * The solution lies in modeling small 2x3 rectangles as knight move and seeing how many of them fit in k*k;
 * This works because we essentially get how many lines and rows we have to multiply for this move to be in k*K;
 * We find this is (k-1)(k-2) for vertical squares since the move takes away 2 from height and 1 from width.
 * For horizontal this will be the same just on the side so 2*(k-1)(k-2). Finally we multiply by two since if we dont distinguish
 * the knights there are exactly two ways how to arrange them in the rectangles - top-l,bot-r or top-r,bot-l.
 *
 *

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
    ll k;
    cin>>k;
    for (ll n=1;n<=k;n++) {
        cout<<(n*n*(n*n-1)/2)-4*(n-1)*(n-2)<<endl;
    }
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