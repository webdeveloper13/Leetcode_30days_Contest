/*
Number of Islands
Solution
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3

*/



class Solution {
public:
    void dfs(vector<vector<char>>& grid,int a,int b)
    {
        int m = grid.size();
        int n = grid[0].size();
        if(a<0 || b<0 || a>=m || b>=n || grid[a][b]!='1')
            return;
        grid[a][b] = '0';
        int checkX[4] = {0,-1,1,0};
        int checkY[4] = {-1,0,0,1};
        
        for(int i=0;i<4;i++)
        {
            dfs(grid,a+checkX[i],b+checkY[i]);
        }
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m==0)
            return 0;
        int n = grid[0].size();
        if(n==0)
            return 0;
        int numIsland = 0;
        for(int i = 0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j);
                    numIsland++;
                    
                }
            }
        }
        
        return numIsland;
    }
};

