#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;//main func
void selectionSort(vector<int>&arr,int n){
for(int i=0;i<n;i++){
  int smallestind=i;
  for(int j=i+1;j<n;j++){
    if(arr[j]<arr[smallestind]){
      smallestind=j;
    }
  }
  swap(arr[i],arr[smallestind]);
}

}
//Print function
void printArray(vector<int>&arr,int n){
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
}
int main(){
  vector<int>arr={4,1,5,2,3};
  int n=arr.size();
  selectionSort(arr,n);
  printArray(arr,n);
  return 0;
}
