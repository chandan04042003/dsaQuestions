class Solution {
public:
    string longestPalindrome(string s) {
        int maxi=0;
        int ansl=0;
        int ansr=0;
        for(int i=0;i<s.size();i++){
            int l=i;
            int r=i;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                l--;
                r++;
            }
            if(r-l+1>maxi){
                ansl=l+1;
                ansr=r-1;
                maxi=r-l+1;
            }
        }

        for(int i=0;i<s.size()-1;i++){
            int l=i;
            int r=i+1;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                l--;
                r++;
            }
            if(r-l+1>maxi){
                ansl=l+1;
                ansr=r-1;
                maxi=r-l+1;
            }
        }
        return s.substr(ansl,ansr-ansl+1);
    }
};