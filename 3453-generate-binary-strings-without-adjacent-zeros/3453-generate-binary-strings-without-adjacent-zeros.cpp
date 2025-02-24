class Solution {
private:
    string strConvert(vector<int> arr){
        string result;
        for (int num : arr) {
        result += to_string(num);
        }
        return result;
    }

    void helper(int i, int zero, vector<string>& ans, vector<int>& arr){
        if(i<0){
            string str= strConvert(arr);
            ans.push_back(str);
            return;
        }
        if(zero==0){
            arr[i]=1;
            helper(i-1,1,ans,arr);
        }
        if(zero==1){
            arr[i]=0;
            helper(i-1,0,ans,arr);
            arr[i]=1;
            helper(i-1,1,ans,arr);
        }
    }
public:
    vector<string> validStrings(int n) {
        // involves printing of combinations ---> backtracking
        vector<int> arr(n);
        vector<string> ans;
        helper(n-1,1,ans,arr);
        return ans;
    }
};