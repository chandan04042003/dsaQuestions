//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    static bool comp(pair <double,int> a,pair <double,int> b){
        return (a.first>b.first);
    }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // Your code here
        vector<pair<double,int>> cont;
        int currWt=0;
        double profit=0;
        int n= wt.size();
        for(int i=0;i<n;i++){
            cont.push_back({((double)val[i]/wt[i]),wt[i]});
        }
        sort(cont.begin(),cont.end(),comp);
        for(int i=0;i<n;i++){
            if(currWt==capacity) break;
            double perWeight=cont[i].first;
            int itemWt=cont[i].second;
            int rem= min(capacity-currWt,itemWt);
            profit += perWeight*rem;
            currWt+=rem;
        }
        return profit;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends