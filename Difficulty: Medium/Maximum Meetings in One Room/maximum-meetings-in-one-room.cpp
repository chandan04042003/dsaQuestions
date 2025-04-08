//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution{
    // this is same as sinding maximum non-overlapping intervals
public:
    static bool comp(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
        return a.second.second<b.second.second;
    }
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<pair<int,pair<int,int>>> meeting;
        for(int i=0;i<N;i++){
            meeting.push_back({i+1,{S[i],F[i]}});
        }
        sort(meeting.begin(),meeting.end(),comp);
        int i=0;
        int j=1;
        vector<int> ans;
        ans.push_back(meeting[0].first);
        while(j<N){
            if(meeting[i].second.second>=meeting[j].second.first){
                j++;
                continue;
            }
            i=j;
            ans.push_back(meeting[j].first);
            j++;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends