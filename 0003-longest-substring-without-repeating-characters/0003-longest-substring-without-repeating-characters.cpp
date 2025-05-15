class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256,0);
        int i=0;
        int j=0;
        int cnt=0;
        int maxi=0;
        while(j<s.size()){
            if(hash[s[j]]==1){
                while(s[i]!=s[j]){
                    hash[s[i]]=0;
                    i++;
                    cnt--;
                }
                hash[s[i]]=0;
                i++;
                cnt--;
            }
            cnt++;
            maxi=max(maxi,cnt);
            hash[s[j]]=1;
            j++;
        }
        return maxi;
    }
};