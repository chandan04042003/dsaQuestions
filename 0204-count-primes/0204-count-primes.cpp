class Solution {
public:
    int countPrimes(int n) {
        vector<int> vec(n,1);
        int cnt=0;
        for(int i=2;i*i<=n;i++){
            if(vec[i]!=1) continue;
            int k=0;
            int j=i*(i+k);
            while(j<n){
               vec[j]=0;
               k++; 
               j=i*(i+k);
            }
        }
        for(int i=2;i<n;i++){
            if(vec[i]==1) cnt++;
        }
        return cnt;
    }
};