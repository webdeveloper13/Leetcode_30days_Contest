/*

Product of Array Except Self
Solution
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)


*/


//Solution 1 : Uses less space. I am using only 1 array here. Time complexity is O(n);
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        int n = nums.size();
        int temp = 1;
        for(int i =0;i<n;i++)
        {
            output.push_back(1);
        }
        
        for(int i=0;i<n;i++)
        {
            output[i] = temp*output[i];
            temp *= nums[i];
        }
        
        temp = 1;
        for(int i=n-1;i>=0;i--)
        {
            output[i] = temp*output[i];
            temp *= nums[i];
        }
        
       return output;
    }
};






//Solution 2 : Uses more space. I am using 2 arrays - prefix and suffix here. Time complexity is O(n);



class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        int n = nums.size();
        int prefix[n];
        int suffix[n];
        prefix[0] = 1;
        suffix[n-1] = 1;
        
        for(int i = 1;i<nums.size();i++)
        {
            prefix[i] = prefix[i-1]*nums[i-1];
        }
        
        for(int i=n-2;i>=0;i--)
        {
            suffix[i] = nums[i+1]*suffix[i+1];
        }
        
        for(int i=0;i<n;i++)
        {
            output.push_back(prefix[i]*suffix[i]);
        }
       
        return output;
    }
};



