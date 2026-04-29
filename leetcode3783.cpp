class Solution {
public:
    int mirrorDistance(int n) {
        long long rev=0;
        int  y=n;
      while(n>0){
        int x=n%10;
         rev=rev*10+x;
        n=n/10;
      }
      int diff=abs(rev-y);
      return diff;
    }
};