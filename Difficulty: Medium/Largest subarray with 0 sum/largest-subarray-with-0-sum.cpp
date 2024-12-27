//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
    // variation of longest subarray with sum k
  public:
    int maxLen(vector<int>& A) {
        // code here
        unordered_map<int,int> mpp; 
        int n=A.size();
        int maxi = 0;
        int sum = 0; 
        for(int i = 0;i<n;i++) {
            sum += A[i]; 
            if(sum == 0) {
                maxi = i + 1; 
            }
            else {
                if(mpp.find(sum) != mpp.end()) {
                    maxi = max(maxi, i - mpp[sum]); 
                }
                else {
                    mpp[sum] = i;
                }
            }   
        }
    
        return maxi; 
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.maxLen(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends