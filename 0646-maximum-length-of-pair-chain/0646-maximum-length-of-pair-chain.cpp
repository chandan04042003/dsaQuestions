class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // Sort the pairs based on the starting value
        sort(pairs.begin(), pairs.end());
        
        // Initialize memoization table with -1 (uncomputed)
        int n = pairs.size();
        vector<vector<int>> dp(n, vector<int>(2002, -1)); // Adjust size to handle all possible lastEnd values
        
        // Helper function to recursively find the longest chain
        return helper(pairs, 0, INT_MIN, dp);
    }
    
private:
    int helper(vector<vector<int>>& pairs, int index, int lastEnd, vector<vector<int>>& dp) {
        if (index == pairs.size()) {
            return 0;
        }
        
        // Adjust lastEnd to fit within the memoization table bounds
        int lastEndKey = lastEnd == INT_MIN ? 0 : lastEnd + 1001; // Offset to handle negative values
        if (dp[index][lastEndKey] != -1) {
            return dp[index][lastEndKey];
        }
        
        int take = 0;
        if (pairs[index][0] > lastEnd) {
            take = 1 + helper(pairs, index + 1, pairs[index][1], dp);
        }
        
        int notTake = helper(pairs, index + 1, lastEnd, dp);
        
        // Store the result in the memoization table
        dp[index][lastEndKey] = max(take, notTake);
        return dp[index][lastEndKey];
    }
};