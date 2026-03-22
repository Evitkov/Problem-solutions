/*
* PROBLEM: Bit Strings (CSES)
 *
 * PROBLEM DESCRIPTION:
 * Your task is to calculate the number of bit strings of length n.
 * For example, if n=3, the correct answer is 8, because the possible bit strings are 000, 001, 010, 011, 100, 101, 110, and 111.
 *
 * SOLUTION DESCRIPTION:
* This is a simple assigment used to only show the fact that modulo can be taken before operations. Since we could never store
* such a large number we have to take the mod after each multiplication this way we guarantee max size of our number being the modulo.
* The result is the same since 13*2%10 =6 or 3*2%10=6 since (10+3)*2 - the 10 is exactly divided by the modulo so it doesnt contribute
* anything to the modulo even when it is multiplied.
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
ll mod = pow(10, 9)+7;
ll result = 2;
for (ll i = 1; i < k; i++) {
result = result * 2 % mod;
}
cout<<result<<endl;
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