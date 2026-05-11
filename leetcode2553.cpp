class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
       vector<int>arr;
vector<int>arr1;
int n=nums.size();
for(int i=0;i<n;i++){
   while(nums[i]!=0){
    int rem=nums[i]%10;
    arr1.push_back(rem);
    nums[i]/=10;
    }
    reverse(arr1.begin(),arr1.end());
    int j=0;
     for(int j = 0; j < arr1.size(); j++) {
        if (j >= arr.size()) arr.push_back({}); 
        arr.push_back(arr1[j]);
        cout << arr1[j] << " ";
    }
    arr1.clear();
}
cout<<endl;
 arr.erase(arr.begin());
  return arr;      
    }
};