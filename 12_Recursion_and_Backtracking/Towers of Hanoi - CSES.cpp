/*
* PROBLEM: Tower of Hanoi (CSES)
 *
 * PROBLEM DESCRIPTION:
 * The Tower of Hanoi game consists of three stacks (left, middle and right)
 * and n round disks of different sizes. Initially, the left stack has all
 * the disks, in increasing order of size from top to bottom.
 * * The goal is to move all the disks to the right stack using the middle stack.
 * On each move you can move the uppermost disk from a stack to another stack.
 * In addition, it is not allowed to place a larger disk on a smaller disk.
 * * Your task is to find a solution that minimizes the number of moves.
 *
 * SOLUTION DESCRIPTION:
 * This problem was really fun for me. Recognizing the pattern was doable but the deep recursion was
 * hard for me to spot. The solution can be described easily then. We go from back if we want to build tower of
 * for example of seven we know there will be a seven at the bottom right and we know we need to build tower of 6
 * in the middle so we free 7 on the left and and can move it to right we can then divide this to 3 parts.
 * We call left stack from middle is our extra and we are trying to get to the right one -to. This means we need to move
 * 1-6 to the extra and then move 7 to right and then build our tower of 6 on top. that means we have to build tower of 6 in the middle 5 on the right ...
 * until we get to base case where we are building tower of 1 - where we move to the desired stack and calls to our recursive methods just dont do anything.
 *
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
void build_tower(int n,int from,int to,int extra) {
    if (n==0) return;

    build_tower(n-1,from,extra,to);
    cout << from<<" "<<to << endl;
    build_tower(n-1,extra,to,from);

}

void solve() {
    int n;
    cin >> n;
    cout<< pow(2,n)-1<<endl;
    build_tower(n,1,3,2);


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