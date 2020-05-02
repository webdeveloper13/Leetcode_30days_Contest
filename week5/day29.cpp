/* Binary Tree Maximum Path Sum
Solution
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    int findMaxSum(TreeNode* root,int &sum)
    {
            if(!root)
                    return 0;
            
            int left = findMaxSum(root->left,sum);
            int right = findMaxSum(root->right,sum);
            int max_one = max(max(left,right)+root->val,root->val);
            int max_two = max(max_one,left+right+root->val);
            sum = max(sum,max_two);
            return max_one;
    }
public:
    int maxPathSum(TreeNode* root) {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            int sum = INT_MIN;
            findMaxSum(root,sum);
            return sum;
        
    }
};