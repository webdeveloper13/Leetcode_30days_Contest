/*
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
*/


class Solution {
public:
    bool checkValidString(string s) {
        stack<int> par;
        stack<int> star;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                par.push(i);
            }
            
            else if(s[i]=='*')
            {
                star.push(i);
            }
            
            else
            {
                if(!par.empty())
                {
                    par.pop();
                }
                
                else if(!star.empty())
                {
                    star.pop();
                }
                
                else
                {
                    return false;
                }
            }
            
        }
        
        while(!par.empty() && !star.empty())
        {
            if(par.top()>star.top())
                return false;
            par.pop();
            star.pop();
        }
        
        return par.empty();
        
    }
};