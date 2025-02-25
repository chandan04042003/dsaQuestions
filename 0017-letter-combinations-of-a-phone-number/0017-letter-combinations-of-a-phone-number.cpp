class Solution {
private:
vector<string> table={
    " ",
    " ",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};
    void helper(int i, string digits, string& str, vector<string>& ans){
        if(i>= digits.size()){
            ans.push_back(str);
            return;
        }
        int num = digits[i] - '0'; 
        string letters = table[num];
        for(int j=0;j<letters.size();j++){
            str.push_back(letters[j]);
            helper(i+1,digits,str,ans);
            str.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; 
        string str="";
        vector<string> ans;
        helper(0,digits,str,ans);
        return ans;
    }
};


