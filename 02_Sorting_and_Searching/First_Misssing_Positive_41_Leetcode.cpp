/*
* PROBLEM: 41-First missing positive (Leetcode)
 *
 * PROBLEM DESCRIPTION:
 * Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
 * You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.
 *
 * SOLUTION DESCRIPTION:
 *
 * The solution is implemented using cyclic sort.
 * The pipeline is -> we put the numbers in the array on the index they belong to starting from 1 to n.
 * Then we do this with the number we swapped until it is in place/it does not have place or we swapped with itself.
 * Since each additional iteration in the nested loop sorts one more element this is still O(n),
 * because even if we sort all in the first while loop the next iterations of the outer for loop will only add constant time
 * and never excute the while loop again

 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        int temp;
        for (int i=0;i<size;i++){

            /*This part is a bit tricky we have to cycle and swap until we get to the
             *same element or it is in correct place
             *
             */

            while(nums[i] <= size && nums[i] > 0 && nums[nums[i]-1] != nums[i]) {
                temp = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = temp;
            }

        }
        for(int i=0;i<size;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return size+1;
    }


};



