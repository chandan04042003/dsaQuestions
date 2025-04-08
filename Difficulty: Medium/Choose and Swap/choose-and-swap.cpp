//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string chooseandswap(string str) {
        // for any character from start, if there exists a character
        // less than of it after it , then swapp , that will be the ans
        set <char> st;
        int n= str.size();
        for(int i=n-1;i>=0;i--){
            st.insert(str[i]);
        }
        for(int i=0;i<n;i++){
            st.erase(str[i]);
            if(st.empty()) break;
            char c1=str[i];
            char c2= *st.begin();
            if(c1>c2){
                for(int j=0;j<n;j++){
                    if(str[j]==c1){
                        str[j]=c2;
                    }
                    else if(str[j]==c2){
                        str[j]=c1;
                    }
                }
                break;
            }
        }
        return str;
    }
};



//{ Driver Code Starts.

int main() {
    Solution obj;
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        cout << obj.chooseandswap(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends