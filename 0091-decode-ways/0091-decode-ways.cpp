class Solution {
private:
    int fn(string s,int i,vector<int>& dp){
        if(i>=s.size()) return 1;
        if(s[i]=='0') return 0;

        if(dp[i]!=-1) return dp[i];

        if(s[i]=='1'){
            int oneDig= fn(s,i+1,dp);
            int twoDig=0;
            if(i+1<s.size()) twoDig=fn(s,i+2,dp);
            return dp[i]=oneDig+twoDig;
        }
        if(s[i]=='2'){
            int oneDig= fn(s,i+1,dp);
            int twoDig=0;
            if(i+1<s.size() && s[i+1]<'7') twoDig=fn(s,i+2,dp);
            return dp[i]=oneDig+twoDig;
        }
        return dp[i]=fn(s,i+1,dp);
    }
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        return fn(s,0,dp);
    }
};