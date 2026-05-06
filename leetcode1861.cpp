

/*1861. Rotating the Box
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an m x n matrix of characters boxGrid representing a side-view of a box. Each cell of the box is one of the following:

A stone '#'
A stationary obstacle '*'
Empty '.'
The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.

It is guaranteed that each stone in boxGrid rests on an obstacle, another stone, or the bottom of the box.

Return an n x m matrix representing the box after the rotation described above.

 

Example 1:



Input: boxGrid = [["#",".","#"]]
Output: [["."],
         ["#"],
         ["#"]]
Example 2:



Input: boxGrid = [["#",".","*","."],
              ["#","#","*","."]]
Output: [["#","."],
         ["#","#"],
         ["*","*"],
         [".","."]]
Example 3:



Input: boxGrid = [["#","#","*",".","*","."],
              ["#","#","#","*",".","."],
              ["#","#","#",".","#","."]]
Output: [[".","#","#"],
         [".","#","#"],
         ["#","#","*"],
         ["#","*","."],
         ["#",".","*"],
         ["#",".","."]]
 

Constraints:

m == boxGrid.length
n == boxGrid[i].length
1 <= m, n <= 500
boxGrid[i][j] is either '#', '*', or '.'.
 
*/

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        // Step 1: Apply gravity horizontally (stones move to the right)
        for (int i = 0; i < m; ++i) {
            int empty_spot = n - 1; // Start tracking from the far right
            for (int j = n - 1; j >= 0; --j) {
                if (boxGrid[i][j] == '*') {
                    // Obstacle resets the landing spot for stones to its left
                    empty_spot = j - 1;
                } else if (boxGrid[i][j] == '#') {
                    // Move stone to the furthest right available spot
                    boxGrid[i][j] = '.';
                    boxGrid[i][empty_spot] = '#';
                    empty_spot--;
                }
            }
        }

        // Step 2: Rotate the grid 90 degrees clockwise
        // Original row i becomes new column (m - 1 - i)
        // Original column j becomes new row j
        vector<vector<char>> rotatedBox(n, vector<char>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rotatedBox[j][m - 1 - i] = boxGrid[i][j];
            }
        }

        return rotatedBox;
    }
};
