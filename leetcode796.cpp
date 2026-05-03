
/*796. Rotate String
Solved
Easy
Topics
premium lock icon
Companies
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
 

Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false
 

Constraints:

1 <= s.length, goal.length <= 100
s and goal consist of lowercase English letters.*/

class Solution {
public:
    bool rotateString(string s, string goal) {
       vector<char>c;
      int n=s.length();
bool seq=false;
for(int i=0;i<n;i++){
c.push_back(s[i]);
}
while(n>0){
int j=0;
int val=c[0];
c.erase(c.begin()+j);
c.push_back(val);
string ss(c.begin(),c.end());
if(ss==goal){
  seq=true;
break;}
n--;
j++;
}

return seq;
 }
};