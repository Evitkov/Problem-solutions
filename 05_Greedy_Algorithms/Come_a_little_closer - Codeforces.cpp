/*
 * PROBLEM: D. Come a Little Closer (Codeforces)
 *
 * PROBLEM DESCRIPTION:
 * The game field is a matrix of size 10^9 x 10^9. There are n monsters on the field at distinct
 * coordinates (x_i, y_i). You are allowed to move exactly one monster to any unoccupied cell
 * at most once. After that, you must choose a single rectangle to destroy all monsters inside it.
 * The cost to destroy them is the area of the chosen rectangle (1 coin per cell).
 * Your task is to find the minimum number of coins (minimum area) required to destroy all monsters.
 *
 * SOLUTION DESCRIPTION:
 * For this problem we have to create a bounding box for all our points which wasnt too hard. Good idea as in this solution is also to keep track which index created this box.
 * With this we can then shift these 4 boundaries by one by looping through the same elements but skipping our boundary point. After each calculation for
 * shifting each boundary point we only pick handle edge case where our smaller boundary is filled with all monsters - in that case we add lenght 1 to the bigger side so we
 * esentially add 1xsmallerside rectangle and the we check if this shifted bounding box is smaller than the previous ones for the boundary points. In the end we output the
 * area of the bounding box which is the smallest after trying the shift on 4 of our boundary points.
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

    vector<ll> a(n);
    vector<ll> b(n);

    ll topx = 0, botx = 2e9;
    ll topy = 0, boty = 2e9;

    int idtopx = 0, idbotx = 0, idtopy = 0, idboty = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];

        if (a[i] < botx) { botx = a[i]; idbotx = i; }
        if (a[i] > topx) { topx = a[i]; idtopx = i; }
        if (b[i] < boty) { boty = b[i]; idboty = i; }
        if (b[i] > topy) { topy = b[i]; idtopy = i; }
    }

    ll minarea = (topx - botx + 1) * (topy - boty + 1);

    int cands[4] = {idtopx, idbotx, idtopy, idboty};

    for (int k = 0; k < 4; k++) {
        int c = cands[k];

        ll curtopx = 0, curbotx = 2e9;
        ll curtopy = 0, curboty = 2e9;

        for (int i = 0; i < n; i++) {
            if (i == c) continue;

            if (a[i] < curbotx) curbotx = a[i];
            if (a[i] > curtopx) curtopx = a[i];
            if (b[i] < curboty) curboty = b[i];
            if (b[i] > curtopy) curtopy = b[i];
        }

        ll width = curtopx - curbotx + 1;
        ll height = curtopy - curboty + 1;
        ll area = width * height;

        if (area > n - 1) {
            minarea = min(minarea, area);
        } else {
            ll exparea = min((width + 1) * height, width * (height + 1));
            minarea = min(minarea, exparea);
        }
    }

    cout << minarea << endl;
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