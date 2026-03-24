/*
    * PROBLEM: Find the zero (Codforces DIV 2 C)
*
 * ==============================================================================
 * PROBLEM STATEMENT:
 * You are given an integer n. There is a hidden array 'a' of length 2n.
 * Each integer from 1 to n appears exactly once in 'a'.
 * The rest of the elements (n elements) are all 0.
 * * THE GOAL:
 * Find any index k (1 <= k <= 2n) such that a[k] == 0.
 * You must do this in no more than (n + 1) queries.
 * Note: The interactor is adaptive (the array can change based on queries
 * but will remain consistent with previous answers).
 * * INTERACTION RULES:
 * 1. Query: Output "? i j" (1 <= i, j <= 2n, i != j).
 * Judge responds:
 * 1  -> if a[i] == a[j]
 * 0  -> if a[i] != a[j]
 * -1  -> Invalid query or limit exceeded (MUST EXIT IMMEDIATELY).
 * * 2. Answer: Output "! k" when you find the index of a 0.
 * (This does not count towards the n+1 limit).
 * * IMPORTANT:
 * - Always output an end of line and flush the output after a query.
 * - If you read -1 at any point, exit immediately to avoid an arbitrary verdict.
 *
     * SOLUTION DESCRIPTION:
     * This interactive problem requires "forcing the system" to pick 2 out of 3 first numbers to be non zero
     * by checking the triangle 12 23 13 this means if there is not identical pair - eg there are not 2 zeroes in a pair
     * there are at least 2 non-zero numbers. Then we check all the disjoint pairs from 45 to n-1 if we get that they are the
     * same we output one of them. If not we can output the last element. This is because we can easily model the whole set having pairs of
     * number and 0 - since every disjoint pair had at least one number and then we have first 3 numbers and the last one. Since there will be 2 zeros
     * hidden in them if we guaranteed that the first three have only one we know the last one will be at the end. This problem wasnt easy since checking
     * all disjoint pairs guarantees zero in the last pair but also uses up n queries in the worst case and 1 query isnt enough to determine which of the two numbers is 0.
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
    ll n;
    cin >> n;
    int answer;
    string out;
    out = "? 1 2";
    cout << out << endl;
    cin >> answer;
    if (answer == -1) return;
    if (answer == 1) {
        cout << "! 1" << endl; return;
    }

    out = "? 2 3";
    cout << out << endl;
    cin >> answer;
    if (answer == -1) return;
    if (answer == 1) {
        cout << "! 2" << endl; return;
    }

    out = "? 1 3";
    cout << out << endl;
    cin >> answer;
    if (answer == -1) return;
    if (answer == 1) {
        cout << "! 3" << endl; return;
    }
    int a1 = 4;
    int a2 = 5;
    bool run = true;
    while (a2 <= 2 * n - 1) {
        out = "?";
        out += " " + to_string(a1);
        out += " " + to_string(a2);
        cout << out << endl;
        cin >> answer;

        if (answer == -1) {
            return;
        }
        if (answer == 1) {
            string res = "! " + to_string(a1);
            cout << res << endl;
            return;
        }
        a1 += 2;
        a2 += 2;
    }
    string res = "! " + to_string(2*n);
    cout << res << endl;
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