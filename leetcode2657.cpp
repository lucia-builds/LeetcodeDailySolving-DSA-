class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
     int n=A.size();
int c=0;
vector<int>C;
int i=0;
while(i<n){
  c=0;
 for(int k=0;k<=i;k++){
  for(int j=0;j<=i;j++){
    if(A[k]==B[j]){
      c++;
    }
  }
 }
 C.push_back(c);
 i++;
}
return C;
    }
};