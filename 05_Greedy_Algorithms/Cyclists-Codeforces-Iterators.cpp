
/*
* PROBLEM: Cyclists (CodeForces contest 1086 div 2 B)
 *
 * PROBLEM DESCRIPTION:
* There are n
* cards placed in a queue called a deck. At any moment, Bob is only able to play the cards that are currently placed in the first k
* positions in the deck. In each turn, Bob selects a card placed in the first k
*  positions, removes it from the deck, plays it, and then places the same card back at the bottom of the deck. In other words, in each turn an element from the first k
* elements in the queue is selected, moved to the end of the queue, and all elements placed after it are moved one index to the front.

* One card is called the win-condition, and Bob wants to play it as many times as possible. However, each card also has a cost needed to play. The i-th card (initially placed at the i-th position) costs Bob ai energy every time it is played.
* The total cost of cards played must not exceed m. Initially, the win-condition card is placed at the p-th place in the queue.
* You need to find out the maximum number of times the win-condition card can be played, ensuring that the total cost does not exceed m
*
 * SOLUTION DESCRIPTION:
* This problem doesnt have a certain trick it is just simulation but the concept how to use c++ iterators
* is new for me hence why included it. The theory is simple in c++ these iterators are just pointers to memory
* with expected size of entry. That means erase function expecting 2 iterators can just be given iterator a.begin() and
* plus the index we want to delete which will create a new iterator - pointer by adding original adress and index*size of entry it knows by the iterator type.
* This also means we can retrive our index just by substracting ref to start form ref to our index.
*
* The solution is then just simulation. We create the array and check if we can reach the win condition. If yes then if
* total cost does not exceed m we update totalcost, wins and winIndex,playIndex - the index of card we play. If we cannot reach it we pick the cheapest card from start to k and we update playindex
* to that. We also update totalcost and substract one from WinIndex since everything after k, which includes our win condition, will be moved by one.
* In the end we just erase the played card and add it to the back.
*
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
   int n,k,p,m;
    cin>>n>>k>>p>>m;
    vi a(n);
    int totalcost =0;
    int wins=0;
    int winIndex = p - 1;
    int play;

    for (int i=0;i<n;i++) {
        cin >> a[i] ;
    }

  while (true) {
      if (winIndex<k) {
          play=winIndex;
          if (a[winIndex]+totalcost<=m) {
              totalcost+=a[winIndex];
              wins++;
              winIndex=n-1;
          }
         else {
             break;
         }
      }
      else {
          auto minIt = min_element(a.begin(),a.begin()+k);
          int min = *minIt;
          play= minIt - a.begin();
          if (min+totalcost<=m) {
              totalcost+=min;
              winIndex--;
          }
          else {
              break;
          }

      }
      int playedCost = a[play];
      a.erase(a.begin() + play);
      a.push_back(playedCost);


  }

    cout << wins << "\n";
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