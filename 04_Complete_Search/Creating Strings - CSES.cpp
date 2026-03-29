/*
* PROBLEM: Creating Strings (CSES)
 *
 * PROBLEM DESCRIPTION:
 * Given a string, your task is to generate all different strings that can be created
 * using its characters.
 *
 * Input:
 * The only input line has a string of length n. Each character is between a–z.
 *
 * Output:
 * First print an integer k: the number of strings.
 * Then print k lines: the strings in alphabetical order.
 *
 * Constraints:
 * 1 <= n <= 8
 *
 * SOLUTION DESCRIPTION:
 * This problem is classic application of recursion and backtracking. We are basically generating permutations in lexicographical order but
 * we have to make sure to not include the same elements. First we create frequency array of letters and then we call our helper with empty string.
 * Our helper function then always picks 1 letter pushes it at end of the string and then calls itself recursively with the frequency array updated by removing
 * our first letter. We do this until we get to base case where length of our string is length of input string. Then we save it and generate other combinations by -
 * first returning from base case to previous recursive layer - and poping from string and restoring frequency array and then generating combinations for the next letters
 * represented by frequencies in the array.
 *
 */

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void generate_combinations(int n, vector<int>& counts, string& current, vector<string>& results) {
    if (current.length() == n) {
        results.push_back(current);
        return;
    }

    for (int i = 0; i < 26; i++) {
        if (counts[i] > 0) {
            counts[i]--;
            current.push_back((char)('a' + i));

            generate_combinations(n, counts, current, results);

            current.pop_back();
            counts[i]++;
        }
    }
}

void solve() {
    string s;
    cin >> s;
    int n = s.length();

    vector<int> counts(26, 0);
    for (int i = 0; i < n; i++) {
        counts[s[i] - 'a']++;
    }

    vector<string> results;
    string current = "";

    generate_combinations(n, counts, current, results);

    cout << results.size() << "\n";

    for (int i = 0; i < results.size(); i++) {
        cout << results[i] << "\n";
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