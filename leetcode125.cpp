// #include<iostream>
// #include <string>
// #include <algorithm>
// #include <cctype>
// using namespace std;
// int main(){
//   string str;
//   str="A man, a plan, a canal: Panama";
//   str.erase(std::remove_if(str.begin(), str.end(), [](unsigned char c) {
//         return !std::isalnum(c);
//     }), str.end());
//     transform(str.begin(), str.end(), str.begin(), ::tolower);
//         string str1=str;
//     reverse(str1.begin(), str1.end());
//     if(str==str1) {
//         cout << "String is palindrome " <<endl;
//     }
//     else{
//       cout<<"not palindrome"<<endl;
//     }
//     return 0;
// }
/*A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.*/
#include<iostream>
#include <string>
#include <algorithm>
#include <cctype>
class Solution {
public:
    bool isPalindrome(string s) {
       s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char c) {
        return !std::isalnum(c);
    }), s.end());
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    string s1=s;
    reverse(s1.begin(), s1.end());
    if(s==s1)
    return 1;
    else
    return 0;
    }
};