class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>premax(n);
        vector<int>ans(n);
        premax[0]=nums[0];
        for(int i=1;i<n;i++){
            premax[i]=max(premax[i-1],nums[i]);
        }

        int suMin=INT_MAX;
        for(int i=n-1;i>=0;i--){
            if(premax[i]>suMin){
                ans[i]=ans[i+1];
            }
            else{
                ans[i]=premax[i];
            }
       suMin=min(suMin,nums[i]);
        }
        return ans;
    }
};