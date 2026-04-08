// 917. Reverse Only Letters
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given a string s, reverse the string according to the following rules:
// All the characters that are not English letters remain in the same position.
// All the English letters (lowercase or uppercase) should be reversed.
// Return s after reversing it.
// Example 1:
// Input: s = "ab-cd"
// Output: "dc-ba"
// Example 2:
// Input: s = "a-bC-dEf-ghIj"
// Output: "j-Ih-gfE-dCba"
// Example 3:
// Input: s = "Test1ng-Leet=code-Q!"
// Output: "Qedo1ct-eeLg=ntse-T!"
// Constraints:
// 1 <= s.length <= 100
// s consists of characters with ASCII values in the range [33, 122].
// s does not contain '\"' or '\\'.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<cctype>
using namespace std;
int main(){
string s = "a-bC-dEf-ghIj";
int l=0,r=s.length()-1;
while(l<=r){
  if(!isalpha(s[l])){
    l++;
  }
  else if(!isalpha(s[r])){
    r--;
  }
  else{
    swap(s[l],s[r]);
    l++;
    r--;
  }
}
  for(int i=0;i<s.length();i++){
    cout<<s[i];
  }
return 0;
}
 //Leetcode solution for 917
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l=0,r=s.length()-1;
        while(l<=r){
            if(!isalpha(s[l])){
                l++;
            }
            else if(!isalpha(s[r])){
                r--;
            }
            else{
                swap(s[l],s[r]);
                l++,r--;
            }
        }
         return s;
    }
   
};