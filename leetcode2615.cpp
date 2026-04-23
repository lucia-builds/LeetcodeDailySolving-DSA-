//Brute Force Approach
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        vector<long long>arr;
  long long dist;
  for(int i=0;i<nums.size();i++){
    dist=0;
    for(int j=0;j<nums.size();j++){
      if(i!=j && nums[i]==nums[j]){
         dist=dist+abs(i-j);
      }  
    }
    arr.push_back(dist);
  }
  return arr;
    }
};
/*2615. Sum of Distances
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given a 0-indexed integer array nums. There exists an array arr of length nums.length, where arr[i] is the sum of |i - j| over all j such that nums[j] == nums[i] and j != i. If there is no such j, set arr[i] to be 0.

Return the array arr.

 

Example 1:

Input: nums = [1,3,1,1,2]
Output: [5,0,3,4,0]
Explanation: 
When i = 0, nums[0] == nums[2] and nums[0] == nums[3]. Therefore, arr[0] = |0 - 2| + |0 - 3| = 5. 
When i = 1, arr[1] = 0 because there is no other index with value 3.
When i = 2, nums[2] == nums[0] and nums[2] == nums[3]. Therefore, arr[2] = |2 - 0| + |2 - 3| = 3. 
When i = 3, nums[3] == nums[0] and nums[3] == nums[2]. Therefore, arr[3] = |3 - 0| + |3 - 2| = 4. 
When i = 4, arr[4] = 0 because there is no other index with value 2. 

Example 2:

Input: nums = [0,5,3]
Output: [0,0,0]
Explanation: Since each element in nums is distinct, arr[i] = 0 for all i.
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109*/
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int l=nums.size();
        vector<long long>arr(l,0);
        unordered_map<int,long long>sumindex;
        unordered_map<int ,long long>count;

        for(int i=0;i<l;i++){
            long long freq=count[nums[i]];
            long long summ=sumindex[nums[i]];
            arr[i]+=freq*i-summ;
            count[nums[i]]++;
            sumindex[nums[i]]=sumindex[nums[i]]+i;
        }
        sumindex.clear();
       count.clear();

for(int i=l-1;i>=0;i--){
            long long freq=count[nums[i]];
            long long summ=sumindex[nums[i]];
            arr[i]+=summ-freq*i;
            count[nums[i]]++;
            sumindex[nums[i]]=sumindex[nums[i]]+i;
        }

return arr;
    }
};