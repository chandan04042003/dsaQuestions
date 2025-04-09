//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
public:
    int minimumDays(int S, int N, int M) {
        
        // if(M > N) return -1;
        // int numOfSun = S / 7;
        // int numPossibleDays = S - numOfSun;
        // int totalFoodReq = S * M;
        // int numDays = totalFoodReq / N;
        // if (totalFoodReq % N != 0) numDays++;

        // if (numDays <= numPossibleDays) return numDays;
        // return -1;
        int totalFood = S * M;
        
        if((7 * M > 6 * N && S > 6) || M > N) return -1;
        
        if(totalFood % N == 0) return totalFood / N;
        else return totalFood / N + 1;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int S, N, M;
        cin >> S >> N >> M;

        Solution ob;
        cout << ob.minimumDays(S, N, M) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends