class Solution {
public:
    bool detectCapitalUse(string word) {
        int countCap=0;
        int initCap=0;
        
        for(int i=0;i<word.size();i++){
            if(word[0]<=90) initCap=1;
            if(word[i]<=90) countCap++;
        } 

        if(countCap==word.size() || countCap==0 || (countCap==1 && initCap==1)) return true;
        return false;
    }
};