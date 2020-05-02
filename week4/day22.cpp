/*
Subarray Sum Equals K
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> m1;
        int currSum = 0;
        int sub = 0;
        for(int i=0;i<n;i++)
        {
           currSum += nums[i];
           
           if(currSum == k)
               sub++;
            
            if(m1.find(currSum-k) != m1.end())
                sub += m1[currSum-k];
            
        
                m1[currSum]++; 
        }
        
        return sub;
        
    }
};