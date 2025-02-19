class Solution {
private:
    int lowerBound(vector<int>& p,int v, long long s){
        int m= p.size();
        int l=0;
        int h=m-1;
        while(l<=h){
            int mid= (l+h)/2;
            long long mul = ((long long) v*(long long)p[mid]);
            if(mul< s) l=mid+1;
            else h= mid-1;
        }
        return l;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n= spells.size();
        int m= potions.size();
        sort(potions.begin(),potions.end());

        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            int val= spells[i];
            int ind= lowerBound(potions,val,success);
            ans[i]= m-ind;
        }
        return ans;
    }
};