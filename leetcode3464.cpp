/*3464. Maximize the Distance Between Points on a Square
Solved
Hard
Topics
premium lock icon
Companies
Hint
You are given an integer side, representing the edge length of a square with corners at (0, 0), (0, side), (side, 0), and (side, side) on a Cartesian plane.

You are also given a positive integer k and a 2D integer array points, where points[i] = [xi, yi] represents the coordinate of a point lying on the boundary of the square.

You need to select k elements among points such that the minimum Manhattan distance between any two points is maximized.

Return the maximum possible minimum Manhattan distance between the selected k points.

The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|.

 

Example 1:

Input: side = 2, points = [[0,2],[2,0],[2,2],[0,0]], k = 4

Output: 2

Explanation:



Select all four points.

Example 2:

Input: side = 2, points = [[0,0],[1,2],[2,0],[2,2],[2,1]], k = 4

Output: 1

Explanation:



Select the points (0, 0), (2, 0), (2, 2), and (2, 1).

Example 3:

Input: side = 2, points = [[0,0],[0,1],[0,2],[1,2],[2,0],[2,2],[2,1]], k = 5

Output: 1

Explanation:



Select the points (0, 0), (0, 1), (0, 2), (1, 2), and (2, 2).

 

Constraints:

1 <= side <= 109
4 <= points.length <= min(4 * side, 15 * 103)
points[i] == [xi, yi]
The input is generated such that:
points[i] lies on the boundary of the square.
All points[i] are unique.
4 <= k <= min(25, points.length)*/

class Solution {
public:
  bool check(vector<long long>& temp, int k, long long side, long long dist) {
        int n = temp.size();
        long long L = 4LL * side; 
        
        vector<long long> newarr(2 * n);
        for (int i = 0; i < n; i++) {
            newarr[i] = temp[i];
            newarr[n + i] = temp[i] + L;
        }

        for (int i = 0; i < n; i++) {
            int count = 1;
            long long pos = newarr[i];
            int idx = i;
            
            for (int c = 1; c < k; c++) {
                long long tar = pos + dist;
                auto it = lower_bound(newarr.begin() + idx + 1, newarr.begin() + i + n, tar);
                
                if (it == newarr.begin() + i + n) {
                    count = -1; 
                    break;
                }
                
                idx = it - newarr.begin();
                pos = newarr[idx];
                count++;
            }
            
            if (count == k && (newarr[i] + L - pos) >= dist) {
                return true;
            }
        }
        return false;
    }

    int maxDistance(int side_int, vector<vector<int>>& points, int k) {
        long long side = side_int; 
        vector<long long> arr;
        
        for (auto &p : points) {
            long long x = p[0];
            long long y = p[1];
            
            if (y == 0) {
                arr.push_back(x); 
            } else if (x == side) {
                arr.push_back(side + y); 
            } else if (y == side) {
                arr.push_back(3 * side - x); 
            } else if (x == 0) {
                arr.push_back(4 * side - y); 
            }
        }
        
        sort(arr.begin(), arr.end());
        
        long long left = 1;
        long long right = side; 
        long long ans = 0;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (check(arr, k, side, mid)) {
                ans = mid;
                left = mid + 1; 
            } else {
                right = mid - 1; 
            }
        }
        
        return ans;
    }
};