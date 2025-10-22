#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isValid(vector<int>&arr,int n, int m,int maximumAlocated){
  int pages=0,studentNo=1;
  if(n<m)
  {
    return -1;
  }
  for(int i=0;i<n;i++){
    if(arr[i]>maximumAlocated){
      return false;
    }
    if(pages+arr[i]<=maximumAlocated){
      pages+=arr[i];
    }
    else{
      studentNo++;
      pages=arr[i];
    }
  }
  return studentNo>m?false:true;
}
int allocation(vector<int>&arr,int n, int m){
  int sum=0,mid=0,ans=-1;
  if(n<m){
    return -1;
  }
  for(int i=0;i<n;i++){
    sum+=arr[i];
  }
  int low=0,high=sum;
  while(low<=high){
   mid=low+(high-low)/2;
    if(isValid(arr,n,m,mid)){
      ans=mid;
      high=mid-1;
    }
    else{
      low=mid+1;
    }
  }
  return ans;
}
int main(){
  vector<int>arr={15,17,20};
  int n=arr.size(),m=2;
  int result=allocation(arr,n,m);
  cout<<"result is:"<<result;
  return 0;
}
