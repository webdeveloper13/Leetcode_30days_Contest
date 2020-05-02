/*Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4

*/


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
            int  m = matrix.size();
            if(m==0)
                    return 0;
            int n = matrix[0].size();
            vector<vector<int>> dp (m+1,vector<int>(n+1,0));
            int ans = 0;
            for(int i=1;i<m+1;i++)
            {
                    for(int j=1;j<n+1;j++)
                    {
                            if(matrix[i-1][j-1]=='0')
                                    dp[i][j]=0;
                            
                            else
                                    dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
                            
                            ans = max(ans,dp[i][j]);
                    }
            }
            
            return ans*ans;
        
    }
};