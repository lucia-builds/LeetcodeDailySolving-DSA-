/*54. Spiral Matrix
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
    int strow=0, stcol=0, endrow=m-1,endcol=n-1;
    vector<int>result; 
    while(strow<=endrow && stcol<=endcol){
        //top
        for(int j=stcol;j<=endcol;j++){
           result.push_back(matrix[strow][j]); }

            //right
        for(int i=strow+1;i<=endrow;i++){
           result.push_back(matrix[i][endcol]); 
        }
            //bottom
        for(int j=endcol-1;j>=stcol;j--){
            if(strow==endrow){
                break;
            }
           result.push_back(matrix[endrow][j]); 

        }
           //left
        for(int i=endrow-1;i>=strow+1;i--){
            if(stcol==endcol){
                break;
            }
           result.push_back(matrix[i][stcol]); 
    }
strow++; endrow--,stcol++,endcol--;}
return result;
    }
};