class Solution {
public:
    bool isPalindrome(string s) {
        string ans;
        for(int i=0;i<s.size();i++){
            if((s[i]>=48 && s[i]<=57) || (s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122)){
                if(s[i]>=65 && s[i]<=90) ans.push_back(s[i]-'A'+'a');
                else ans.push_back(s[i]);   
            }
        }
        string rev=ans;
        reverse(ans.begin(),ans.end());
        if(ans==rev) return true;
        return false;
    }
};