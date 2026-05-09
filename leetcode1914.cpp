#include<iostream>
#include<vector>
using namespace std;

int main(){
vector<vector<int>>grid={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
 int k=2;
 int top=0;
 int left=0;
 int right=grid[0].size()-1;
 int down=grid.size()-1;


while(top < down && left < right) {
    vector<int> ans;
    
    for(int i = left; i <= right; i++) ans.push_back(grid[top][i]);
    for(int i = top + 1; i <= down; i++) ans.push_back(grid[i][right]);
    for(int i = right - 1; i >= left; i--) ans.push_back(grid[down][i]);
    for(int i = down - 1; i > top; i--) ans.push_back(grid[i][left]);

    int L = ans.size();
    int netK = k % L; 
    int startIdx = netK; 

    int count = 0;
    for(int i = left; i <= right; i++) grid[top][i] = ans[(count++ + netK) % L];
    for(int i = top + 1; i <= down; i++) grid[i][right] = ans[(count++ + netK) % L];
    for(int i = right - 1; i >= left; i--) grid[down][i] = ans[(count++ + netK) % L];
    for(int i = down - 1; i > top; i--) grid[i][left] = ans[(count++ + netK) % L];

    top++; left++; down--; right--;
}

for(int i=0;i<grid.size();i++){
    for(int j=0;j<grid[0].size();j++){
        cout<<grid[i][j]<<" ";
    }
    cout<<endl;
  }

  return 0;
}