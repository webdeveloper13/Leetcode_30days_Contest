/*
Bitwise AND of Numbers Range
Solution
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0
*/



//Solution 1: Okayish solution
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        // i am diving into an optimal procedure
        //till your and m and n are not same keep shifting right
         //and keep the count;
        //finally shift left by that count;
            
        int right = 0;
        while(m!=n)
        {
                m=m>>1;
                n= n>>1;
                right++;
        }
            
        return m<<right;    
            
          /*00000101 = 5
            00000111 = 7
            
                    00000010
                    00000011
                    
                    
                    00000001
                    00000001
            */
    }
};


    
//Solution 2: Best solution

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
       while(n>m)
               n = (n & (n-1));
            
       return n&m;     
    }
};


    
    