/*
Code


Testcase
Testcase
Test Result
739. Daily Temperatures
Medium
Topics
premium lock icon
Companies
Hint
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
 

Constraints:

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100*/
// #include<iostream>
// #include<algorithm>
// #incude<unordered_map>
// #include<vector>
// using namespace std;
// int main(){
//   vector<int> temperatures={73,74,75,71,69,72,76,73};
//   vector<int>arr;
//   int c=0;
//   for(int i = 0; i < temperatures.size(); i++) {
//     bool found = false;
//     for(int j = i + 1; j < temperatures.size(); j++) {
//         if(temperatures[j] > temperatures[i]) {
//             arr.push_back(j - i); 
//             found = true;
//             break;
//         }
//     }
//     if(!found) {
//         arr.push_back(0); 
//     }
// }


//  for(int k=0;k<arr.size();k++){
//   cout<<arr[k]<<" ";
//  }

// return 0;
// }

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      int n=temperatures.size();
  vector<int>res(n,0);
   stack<int> st;
  for(int i=0;i<temperatures.size();i++){
   
    while(!st.empty() && temperatures[i]>temperatures[st.top()]){
      int ind=st.top();
      st.pop();
      res[ind]=i-ind;
    }
    st.push(i);
  }
return res;

    }
};