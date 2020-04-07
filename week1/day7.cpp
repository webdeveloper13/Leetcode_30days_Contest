 /*
 Counting Elements
Solution
Given an integer array arr, count element x such that x + 1 is also in arr.

If there're duplicates in arr, count them seperately.

 

Example 1:

Input: arr = [1,2,3]
Output: 2
Explanation: 1 and 2 are counted cause 2 and 3 are in arr.
Example 2:

Input: arr = [1,1,3,3,5,5,7,7]
Output: 0
Explanation: No numbers are counted, cause there's no 2, 4, 6, or 8 in arr.

*/

Solution 1: Using hash set

class Solution {
public:
    int countElements(vector<int>& arr) {
       unordered_multiset<int> um1;
        int count=0;
       for(int i=0;i<arr.size();i++)
       {
           um1.insert(arr[i]);
       }
        
       for(int i=0;i<arr.size();i++)
       {
           if(um1.find(arr[i]+1)!=um1.end())
               count++;
       }
       
        return count;
    }
};


Solution 2:


class Solution {
public:
    int countElements(vector<int>& arr) {
        int count = 0;
        
        for(int i=0;i<arr.size();i++)
        {
            int x = arr[i]+1;
            
            for(int j=0;j<arr.size();j++)
            {
                if(arr[j]==x){
                    count++;
                    break;
                }
                
            }
        }
        
        return count;
        
    }
};