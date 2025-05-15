class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> mp;
        vector<vector<string>> ans;
        for(string& word: strs){
            vector<int> freq(26,0);
            for(int i=0;i<word.size();i++){
                freq[word[i]-'a']++;
            }
            mp[freq].push_back(word);
        }

        for(auto& vec: mp){
            ans.push_back(vec.second);
        }
        return ans;
    }
};