//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
  // MEMOIZATION
    // Recursive function to calculate the maximum points for the ninja training
    int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {
      // If the result for this day and last activity is already calculated, return it
      if (dp[day][last] != -1) return dp[day][last];
    
      // Base case: When we reach the first day (day == 0)
      if (day == 0) {
        int maxi = 0;
        // Calculate the maximum points for the first day by choosing an activity
        // different from the last one
        for (int i = 0; i <= 2; i++) {
          if (i != last)
            maxi = max(maxi, points[0][i]);
        }
        // Store the result in dp array and return it
        return dp[day][last] = maxi;
      }
    
      int maxi = 0;
      // Iterate through the activities for the current day
      for (int i = 0; i <= 2; i++) {
        if (i != last) {
          // Calculate the points for the current activity and add it to the
          // maximum points obtained so far (recursively calculated)
          int activity = points[day][i] + f(day - 1, i, points, dp);
          maxi = max(maxi, activity);
        }
      }

  // Store the result in dp array and return it
  return dp[day][last] = maxi;
}
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        // Create a memoization table (dp) to store intermediate results
      vector<vector<int>> dp(n, vector<int>(4, -1));
      // Start the recursive calculation from the last day with no previous activity
      return f(n - 1, 3, arr, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends