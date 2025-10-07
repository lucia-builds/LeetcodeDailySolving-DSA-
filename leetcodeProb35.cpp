/*Search Insert Position
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.
Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2
Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4
Constraints:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
   int mid,low=0,high=nums.size()-1;
   bool found=false;
   while(low<=high){
    mid=low+(high-low)/2;
    if(nums[mid]==target){
        found=true;
        return mid;
        break;
    }
    else if(nums[mid]<target)
      low=mid+1;
      else if(nums[mid]>target)
      high=mid-1;
   }  
 if(found==false){
        nums.push_back(target);
        sort(nums.begin(),nums.end());
        low=0,high=(nums.size()-1);
        while (low <= high) {
        mid = low + (high - low) / 2;

        if (nums[mid] == target) {
           return mid;
            break;
        }

        if (nums[mid] < target) {
            low = mid + 1;
        } else if(nums[mid] > target) {
            high = mid - 1;
        }}
        }
    
   return mid;
    }
};