class Solution {
public:
    int maxVowels(string s, int k) {
        int maxi=0;
        int cnt=0;
        int n=s.size();
        for(int i=0;i<k;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                cnt++;
            }
        }
        maxi=max(maxi,cnt);
        for(int i=k;i<n;i++){
            char x=s[i-k];
            if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u') cnt--;
            char y=s[i];
            if(y=='a'||y=='e'||y=='i'||y=='o'||y=='u') cnt++;
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};