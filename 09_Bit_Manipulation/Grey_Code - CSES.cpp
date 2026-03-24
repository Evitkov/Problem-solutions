/*
 * PROBLEM: Gray Code (CSES)
 *
 * REAL-WORLD CONTEXT:
* Standard binary is fine for doing math inside the cpu. But when you have to track physical states or move data across messy hardware boundaries,
* normal binary is terrible because changing from 3 (011) to 4 (100) flips three wires at once. In the real physical world, wires don't flip perfectly at the exact same
* nanosecond, so the system might accidentally read a garbage intermediate state like 111.
 * * Gray code fixes this by guaranteeing only one bit changes at a time. You see this used in physical sensors like rotary volume knobs (so a vibrating sensor doesn't glitch out reading a boundary),
 * in microchip design when passing memory pointers between a fast cpu and a slow network chip, and in wifi/5g where radio wave shapes are mapped using gray code
 * so a distorted signal only causes a tiny 1-bit error.
 *
 *
 * * PROBLEM DESCRIPTION:
 * A Gray code is a list of all 2^n bit strings of length n, where any
 * two successive strings differ in exactly one bit (i.e., their Hamming
 * distance is one).
 * Your task is to create a Gray code for a given length n (1 <= n <= 16).
 * You need to output 2^n lines that describe the Gray code. If there are
 * multiple valid sequences, you can print any valid solution.
 *
 * SOLUTION DESCRIPTION:
 * If we write out such a series of bits we can spot a pattern. First half is always starting with
 * a 0 and second with a 1. Also behind those leading numbers the rest of the binary digits are exactly mirrored.
 * - For example for n=3 we start with (0)00 -> (0)01 and end with (1)01 -> (1)00 -
 * This means we can create the graycode for n from gray code for n-1 by just creating a new array
 * and in the first half pushing all entries with added 0 in front of them, and then traversing the array
 * for n-1 from the end and adding 1 in front. We do this from n=2 which uses our base case 0,1 for n=1
 * until n and then we print all strings in the array.
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

void solve() {
    int n;
    cin >> n;
    vector<string> gray = {"0", "1"};

    for (int i = 2; i <= n; i++) {
        vector<string> temp;

        for (int j = 0; j < gray.size(); j++) {
            temp.push_back("0" + gray[j]);
        }

        for (int j = gray.size() - 1; j >= 0; j--) {
            temp.push_back("1" + gray[j]);
        }

        gray = temp;
    }

    for (string s : gray) {
        cout << s << "\n";
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