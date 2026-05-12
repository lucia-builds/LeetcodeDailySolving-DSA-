class Solution {
public:
bool check(vector<vector<int>>&tasks,int mid){
  int curr_energy=mid;
  for(const auto&task :tasks){
    int actual=task[0];
    int minimum=task[1];

    if(curr_energy < minimum){
      return false;
    }
    curr_energy-=actual;
  }
return true;
}


    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](const vector<int>& a, const vector<int>& b){
  return (a[1]-a[0])>(b[1]-b[0]);
});
int low=0;
int high=0;
for(int i=0;i<tasks.size();i++){
  for(int j=0;j<tasks[0].size();j=j+2){
   low=low+tasks[i][j];
  }
  for(int k=1;k<tasks[0].size();k=k+2){
    high=high+tasks[i][k];
  }
}
int target=0;
while(low<=high){
  int mid=low+(high-low)/2;
   if(check(tasks,mid)){
    target=mid;
    high=mid-1;
   }
   else{
    low=mid+1;
   }
}
return target;
    }
};