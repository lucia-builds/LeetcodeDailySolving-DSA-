class Solution {
public:
    int rotatedDigits(int n) {
         int c_nos = 0;

        unordered_map<int,int> um = {
            {0,0},{1,1},{8,8},
            {2,5},{5,2},{6,9},{9,6}
        };

        for(int i = 1; i <= n; i++){
            int num = i;
            bool isDiff = false;
            bool isValid = true;

            while(num > 0){
                int digit = num % 10;

                if(um.find(digit) == um.end()){
                    isValid = false; 
                    break;
                }

                if(um[digit] != digit)
                    isDiff = true;

                num /= 10;
            }

            if(isValid && isDiff)
                c_nos++;
        }

        return c_nos;
    }
};