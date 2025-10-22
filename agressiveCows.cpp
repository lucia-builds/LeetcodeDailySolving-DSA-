#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
bool isValid(vector<int>&arr,int n,int m,int allocated){
  int cows=1,lastStallpos=arr[0];
  for(int i=0;i<n;i++){
    if(arr[i]-lastStallpos>=allocated){
      cows++;
      allocated=arr[i];
    }
    if(cows==m){
      return true;
    }
  }
  return false;
}


int CowsAllocation(vector<int>&arr,int n,int m){
  sort(arr.begin(),arr.end());
  int mid,ans=-1,low=1,high=arr[n-1]-arr[0];
  while(low<=high){
   mid=low+(high-low)/2;
   if(isValid(arr,n,m,mid)){
    ans=mid;
    low=mid+1;
   }
   else{
    high=mid-1;
   }
  }
  return ans;
}
int main(){
  vector<int>arr={1,2,8,4,9};
  int n=arr.size();
  int m=3,result;
  result=CowsAllocation(arr,n,m);
return 0;
}