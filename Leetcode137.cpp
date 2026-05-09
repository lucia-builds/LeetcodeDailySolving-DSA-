/*137. Single Number II
Solved
Medium
Topics
premium lock icon
Companies
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
 

Constraints:

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    unordered_map<int,int>mp;
 for(int x: nums){
  mp[x]++;
 }
 for(auto it: mp){
  if(it.second>1){
    int y=it.first;
    nums.erase(remove(nums.begin(),nums.end(),y),nums.end());
  }
 }
 return nums[0];
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        
        for(auto x: nums){
            m[x]++;
        }

        for(auto x: m){
            if(x.second == 1){
                return x.first;
            }
        }
        
        return -1;
    }
};