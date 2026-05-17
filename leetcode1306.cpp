
/*1306. Jump Game III
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach any index with value 0.

Notice that you can not jump outside of the array at any time.

 

Example 1:

Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 
Example 2:

Input: arr = [4,2,3,0,3,1,2], start = 0
Output: true 
Explanation: 
One possible way to reach at index 3 with value 0 is: 
index 0 -> index 4 -> index 1 -> index 3
Example 3:

Input: arr = [3,0,2,1,2], start = 2
Output: false
Explanation: There is no way to reach at index 1 with value 0.
 

Constraints:

1 <= arr.length <= 5 * 104
0 <= arr[i] < arr.length
0 <= start < arr.length*/
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int>new_arr;
        new_arr.push_back(start);
        vector<bool>visited(n,false);
        visited[start]=true;
        bool reachZero=false;
        while(!new_arr.empty()){
            int i=new_arr.back();
            new_arr.pop_back();
            if(arr[i]==0){
                reachZero=true;
                break;
            }
            int reachRight=i+arr[i];
            if(reachRight<n && !visited[reachRight]){
                visited[reachRight]=true;
                new_arr.push_back(reachRight);
            }
int leftReach=i-arr[i];
if(leftReach>=0 && !visited[leftReach]){
    visited[leftReach]=true;
    new_arr.push_back(leftReach);
}

        }

        if(reachZero){
            return true;
        }
        return false;

    }
};