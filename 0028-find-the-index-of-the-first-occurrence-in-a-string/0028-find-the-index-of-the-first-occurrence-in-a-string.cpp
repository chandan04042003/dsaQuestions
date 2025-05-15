class Solution {
public:
    int strStr(string haystack, string needle) {
        int n= haystack.size();
        int m= needle.size();
        int ind=-1;

        for(int k=0;k<n;k++){
            int i=k;
            int j=0;
            while(i<n && j<m && haystack[i]==needle[j]){
                if(j==0) ind=i;
                i++;
                j++;
            }
            if(j>=m) break;
            ind=-1;
        }
        return ind;
    }
};