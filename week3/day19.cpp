/*
Search in Rotated Sorted Array
Solution
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

class Solution {
public:
    int optimised_search(vector<int>& nums,int l,int h,int x)
    {
        if(l>h)
            return -1;
        
        int mid = (l+h)/2;
        
        if(nums[mid]==x)
            return mid;
        
        if(nums[l]<=nums[mid])
        {
            if(x>=nums[l] && x<=nums[mid])
            {
                return optimised_search(nums,l,mid-1,x);
            }
            
            return optimised_search(nums,mid+1,h,x);
        }
        
        if(x>=nums[mid] && x<=nums[h])
            return optimised_search(nums,mid+1,h,x);
        
        return optimised_search(nums,l,mid-1,x);
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pos = optimised_search(nums,0,n-1,target);
        return pos;
    }
};