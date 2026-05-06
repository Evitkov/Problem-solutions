/*
 * PROBLEM: C. Zhily and Bracket Swapping (Codeforces)
 *
 * PROBLEM DESCRIPTION:
 * Deep in the wilderness, Zhily and Jily discovered two sequences composed of brackets.
 * Each sequence carries some logical structure, but neither of them is necessarily a
 * regular bracket sequence on its own. They found that by swapping brackets between
 * the two sequences, they could repair them. They wish to make both sequences regular
 * bracket sequences by swapping brackets between them. A regular bracket sequence is a
 * sequence consisting of '(' and ')', which can be turned into a valid math expression
 * by inserting 1 and + any number of times.
 * You are given two bracket sequences a and b of even length n. You can choose a position
 * i and swap a_i and b_i any number of times. Determine whether you can turn both a and
 * b into regular bracket sequences.
 *
 * SOLUTION DESCRIPTION:
 * Firstly we check if either of the sequences doesnt start with ) which would give us fast exit and then we see if the total value
 * for the strings combined is 0. I assigned the value based on simple algorithm looping and treting ( as +1 and ) as -1;
 * Then we just always greedily try to keep our running totals as close as possible by picking the negative step for the bigger running total
 * if the steps are different. At the end of each iteration we just check if our running total for each of the strings didnt go below 0 since this
 * is the invalid state  - more ) than ( could never work out. Why this greedy startegy works? I was bit confused at the start but it makes sense, if we
 * give away point from the safer one could it not be that he might go below -1 because of that? The answer is no since there are 2 possible options - we can retaliate
 * by giving him the positive steps in future if there are any. If there wasnt enough steps we could save the bigger one after taking away all those both negative steps would
 * bring our smaller one to -1 anyways.
 *
 *
 * */
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
    string a;
    string b;
    cin >> a >> b;
    vector<char> stack1;
    vector<char> stack2;
    int count1 =0;
    int count2 =0;
    if (a[0]==')'||b[0]==')') {
        cout << "No" << endl;
        return;
    }

    for (int i=0;i<n;i++) {
        if (a[i]=='(') {
            count1++;
        }
        else {
            count1--;
        }
    }

    for (int i=0;i<n;i++) {
        if (b[i]=='(') {
            count2++;

        }
        else {
            count2--;
        }
    }
    if (count1+count2!=0) {
        cout << "No" << endl;
        return;
    }

    int counter = 0;
    int total1 = 0;
    int total2 = 0;

    while (counter<n) {
        int step1 = 0;
        int step2 = 0;

        if (a[counter]=='(') {
            step1++;
        }
        else {
            step1--;
        }
        if (b[counter]=='(') {
            step2++;
        }else {
            step2--;
        }

        if (step1 == step2) {
            total1 += step1;
            total2 += step2;
        } else {
            if (total1 < total2) {
                total1++;
                total2--;
            } else {
                total2++;
                total1--;
            }
        }

        if (total1 < 0 || total2 < 0) {
            cout << "No" << endl;
            return;
        }

        counter++;
    }

    if (total1 == 0 && total2 == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    fast_io();
    int t = 1;
    cin >> t ;
    while (t--) {
        solve();
    }

    return 0;
}