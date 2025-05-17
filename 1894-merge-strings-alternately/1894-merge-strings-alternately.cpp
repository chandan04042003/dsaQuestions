class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        string merged;
        int i=0;
        int j=0;
        while(i<n && j<m){
            merged.push_back(word1[i]);
            merged.push_back(word2[j]);
            i++;
            j++;
        }
        while(i<n){
            merged.push_back(word1[i]);
            i++;   
        }
        while(j<m){
            merged.push_back(word2[j]);
            j++;   
        }
        return merged;
    }
};