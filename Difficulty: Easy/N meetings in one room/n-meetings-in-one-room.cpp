//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool compareEnd(vector<int> a, vector<int> b){
        return a[1]<b[1];
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n= start.size();
        int cnt=1;
        vector<vector<int>> cont;
         for (int i = 0; i < n; i++) {
            cont.push_back({start[i], end[i]});
        }
        sort(cont.begin(),cont.end(),compareEnd);
        int i=0;
        int j=1;
        while(i<n && j<n){
            if(cont[j][0]<=cont[i][1]){
                j++;
                continue;
            }
            cnt++;
            i=j;
            j++;
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends