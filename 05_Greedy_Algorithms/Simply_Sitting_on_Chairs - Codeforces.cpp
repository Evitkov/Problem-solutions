/*
* PROBLEM: B. Simply Sitting on Chairs (Codeforces - Div 2 B)
 *
 * PROBLEM DESCRIPTION:
 * There are n chairs in a row, initially all unmarked. You are given a permutation p of length n.
 * You visit each chair sequentially, starting from the 1-st chair. At the i-th chair:
 * - If the i-th chair is already marked, you end the game immediately without sitting on it.
 * - Otherwise, you can choose to sit on the chair or skip it.
 * - If you choose to sit, after standing up, you mark the p_i-th chair and move to the next.
 * The game ends when all n chairs are visited or a marked chair is reached.
 * The task is to determine the maximum number of chairs you can sit on.
 *
 * SOLUTION DESCRIPTION:
 * This problem seemed like dp at the start to me and i got really tangled trying to implement that. Just to dinf that the solution
 * is indeed much easier using simple invariant if we go through the array and take only the chairs that mark our chair or the chair in teh past
 * we are sure to find the maximum number of chairs - why? Because if we take a chair that marks chair in future we add one and guarantee to also take away one
 * from the future in the best case. Very important is to use the properties of permutations here as often in competitive programming that is here since one chair is gonna
 * mark a chair after it there is guaranteed at least one chair in our array that marks chair infront of itself. (This is also logical since only solution how this would not
 * work out is when we got to chair, that has chairs that mark chairs after, after itself - this would only make sense lets say if the problem wanted us to stop somewhere).
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

    ll counter=0;
    int temp;
    for (ll i=1;i<=n;i++) {
        cin >> temp;
        if (temp<=i) {
            counter++;
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