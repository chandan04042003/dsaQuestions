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
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Create a memoization table (dp) to store intermediate results
    //   vector<vector<int>> dp(n, vector<int>(4, -1));
    //   // Start the recursive calculation from the last day with no previous activity
    //   return f(n - 1, 3, points, dp);
    
    // TABULATION
    // Create a 2D DP (Dynamic Programming) table to store the maximum points
      // dp[i][j] represents the maximum points at day i, considering the last activity as j
      vector<vector<int>> dp(n, vector<int>(4, 0));
    
      // Initialize the DP table for the first day (day 0)
      dp[0][0] = max(points[0][1], points[0][2]);
      dp[0][1] = max(points[0][0], points[0][2]);
      dp[0][2] = max(points[0][0], points[0][1]);
      dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    
      // Iterate through the days starting from day 1
      for (int day = 1; day < n; day++) {
        for (int last = 0; last < 4; last++) {
          dp[day][last] = 0;
          // Iterate through the tasks for the current day
          for (int task = 0; task <= 2; task++) {
            if (task != last) {
              // Calculate the points for the current activity and add it to the
              // maximum points obtained on the previous day (recursively calculated)
              int activity = points[day][task] + dp[day - 1][task];
              // Update the maximum points for the current day and last activity
              dp[day][last] = max(dp[day][last], activity);
            }
          }
    }
  }

  // The maximum points for the last day with any activity can be found in dp[n-1][3]
  return dp[n - 1][3];
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
