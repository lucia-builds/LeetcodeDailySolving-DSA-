/*43. Multiply Strings
Solved
Medium
Topics
premium lock icon
Companies
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
 

Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.*/

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")
        return "0";
        int n1=num1.length();
        int n2=num2.length();
        vector<int>res(n1+n2,0);
        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
            int multiplication=(num1[i]-'0')*(num2[j]-'0');
            int summm=multiplication +res[i+j+1];
            res[i+j+1]=summm%10;
            res[i+j]+=summm/10;
            }
        }
        string s="";
        for(int num: res){
            if(!(s.empty() &&num==0)){
 s += to_string(num);
            }
        }
        return s;
    }
};
