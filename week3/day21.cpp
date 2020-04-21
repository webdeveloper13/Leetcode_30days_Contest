/* 
 Leftmost Column with at Least a One
Solution
(This problem is an interactive problem.)

A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. If such index doesn't exist, return -1.

You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:

BinaryMatrix.get(x, y) returns the element of the matrix at index (x, y) (0-indexed).
BinaryMatrix.dimensions() returns a list of 2 elements [n, m], which means the matrix is n * m.
Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.

For custom testing purposes you're given the binary matrix mat as input in the following four examples. You will not have access the binary matrix directly.

 
Example 1:
Input: mat = [[0,0],[1,1]]
Output: 0
*/


/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> v;
        v = binaryMatrix.dimensions();
        int n = v[0];
        int m = v[1];
        int val;
        int curr=-1;
        int i=0;
        int j=m-1;
        while(i<=n-1 && j>=0)
        {
            val = binaryMatrix.get(i,j);
            if(val==0)
            {
               i++;
            }
            
            else
            {
                curr = j;
                j--;
            }
        }
        
        return curr;
    }
};