class Solution {
public:
void backtracking(int start,vector<int>& candidates,int target,vector<int>&ans,vector<vector<int>>&res){
    if(target==0){
        res.push_back(ans);
        return;
    }
    if(target<0)
    return;
    for(int i=start;i<candidates.size();i++){
        ans.push_back(candidates[i]);
        backtracking(i,candidates,target-candidates[i],ans,res);
        ans.pop_back();
    }

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>ans;
        backtracking(0,candidates,target,ans,res);
        return res;
    }
};