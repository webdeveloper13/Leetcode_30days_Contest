/*Perform String Shifts
Solution
You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:

direction can be 0 (for left shift) or 1 (for right shift). 
amount is the amount by which string s is to be shifted.
A left shift by 1 means remove the first character of s and append it to the end.
Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
Return the final string after all operations.
Example 1:

Input: s = "abc", shift = [[0,1],[1,2]]
Output: "cab"
Explanation: 
[0,1] means shift to left by 1. "abc" -> "bca"
[1,2] means shift to right by 2. "bca" -> "cab"


*/

class Solution {
    public String stringShift(String s, int[][] shift) {
            int left = 0;
            int right =0;
            for(int i = 0;i<shift.length;i++)
            {

                if(shift[i][0]==0)
                {
                    left += shift[i][1];
                }

                else
                {
                    right += shift[i][1];
                }
            }

          int val = left - right;
          if(val>s.length()|| -val>s.length())
          {
              val = val%s.length();
          }
        
          if(val<0)
          {
              val = val + s.length();
          }
        
          return s.substring(val) + s.substring(0,val);

        }
}