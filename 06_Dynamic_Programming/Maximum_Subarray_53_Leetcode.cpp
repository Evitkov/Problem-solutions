/*
* PROBLEM: 53-Maximum Subarray (Leetcode)
 *
 * PROBLEM DESCRIPTION:
 * Given an integer array nums, find the subarray with the
 * largest sum, and return its sum.
 *
 * SOLUTION DESCRIPTION:
 * To achieve the result in the time limit we need to iterate through the array only once.
 * We achieve this by keeping track of the current subarray sum. The logic is then simple.
 * If we are adding another element to the subarray and it is bigger or same as the added number we allways increase the sum and continue.
 * If the next element alone is bigger we reassign our sum to it.
 * Then again start adding until element is bigger standalone.
 *
 * In the end we return totalbest subarray sum we got by comparing individual subarray sums
 * after each iteration against the biggest subarray sum we have seen.

 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    
        if (nums.empty()) {
            return 0;
        }

        int sum=nums[0];
        int totalbest=nums[0];
        
        for (int i=1;i<nums.size();i++) {
           
            sum = max(nums[i], sum + nums[i]);
            totalbest = max(sum, totalbest);
        }
        
        return totalbest;
    }
};