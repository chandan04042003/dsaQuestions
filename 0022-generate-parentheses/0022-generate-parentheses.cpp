class Solution {
private: 
    void helper(int i, int c1, int c2, vector<char>& arr, vector<string>& ans) {
        if (i == -1) { 
            ans.emplace_back(arr.begin(), arr.end());
            return;
        }

        if (c1 > 0 && c1 > c2) {
            arr[i] = '(';
            helper(i - 1, c1 - 1, c2, arr, ans);
        }
        if (c2 > 0) {
            arr[i] = ')';
            helper(i - 1, c1, c2 - 1, arr, ans);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        /* invloves printing of
        combinatorics --->
        backtracking */

        int m = 2 * n;
        vector<char> arr(m, '*');
        vector<string> ans;
        int c1 = n, c2 = n;
        helper(m - 1, c1, c2, arr, ans);
        return ans;
    }
};