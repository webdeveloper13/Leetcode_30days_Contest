/*Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/


int kadane_Sub (int *nums,int numsSize)
{
 int curr_max=0,max_so_far=0;
    for(int i=0;i<numsSize;i++)
    {
        curr_max += nums[i];
        
        if(curr_max<0)
        {
            curr_max=0;
        }
        
        if(curr_max>max_so_far)
        {
            max_so_far = curr_max;
        }
        
    }
    
    
    return max_so_far;
    
}


int maxSubArray(int* nums, int numsSize){
    
    int neg_count =0;
    int maxim = INT_MIN;
    
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]>maxim)
            maxim = nums[i];
        
        if(nums[i]<0)
            neg_count++;
            
    }
    
    if(neg_count == numsSize)
        return maxim;
    
    
    int maximum = kadane_Sub (nums,numsSize);
    
    
    return maximum;
    
 }

