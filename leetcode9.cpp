/*9. Palindrome Number
Given an integer x, return true if x is a palindrome, and false otherwise.
Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.*/

//1st method to convert integer to string
#include<iostream>
#include <string> 
#include <algorithm>
class Solution {
public:
    bool isPalindrome(int x) {
    std::string y=to_string(x);
     std::string copyx =y;
     reverse(y.begin(), y.end());
       if(copyx==y)
       return true;
       else
       return false;
    }
};
//2nd method
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        long reverse = 0;
        int xcopy = x;

        while (x > 0) {
            reverse = (reverse * 10) + (x % 10);
            x /= 10;
        }

        return reverse == xcopy;        
    }
};