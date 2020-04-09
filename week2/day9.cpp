/* Backspace String Compare
Solution
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?

*/



class Solution {
public:
    bool backspaceCompare(string S, string T) 
    {
        
        deque<char> q1;
        for(int i = 0;i<S.length();i++)
        {
            if(S[i]!='#')
            {
                q1.push_back(S[i]);
            }
            
            else if(!q1.empty())
            {
                q1.pop_back();
            }
        }
        
        string com1 = "";
        while(!q1.empty())
        {
            com1 +=q1.front();
            q1.pop_front();
        }
        
        deque<char> q2;
        for(int i = 0;i<T.length();i++)
        {
            if(T[i]!='#')
            {
                q2.push_back(T[i]);
            }
            
            else if(!q2.empty())
            {
                q2.pop_back();
            }
        }
        
        string com2 = "";
        while(!q2.empty())
        {
            com2 +=q2.front();
            q2.pop_front();
        }
        
        
        if(com1.compare(com2)==0)
            return true;
        
        else
            return false;
        
        
    }
};