/*1314. Matrix Block Sum
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:

i - k <= r <= i + k,
j - k <= c <= j + k, and
(r, c) is a valid position in the matrix.
 

Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]
Example 2:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n, k <= 100
1 <= mat[i][j] <= 100*/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
    int cols = mat[0].size();
    vector<vector<int>> result(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int summ = 0;
            for (int p = max(0, i - k); p <= min(rows - 1, i + k); p++) {
                for (int w = max(0, j - k); w <= min(cols - 1, j + k); w++) {
                    summ += mat[p][w];
                }
            }
            result[i][j] = summ;
        }
    }
    return result;
    }
};