//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int,int>> stocks;
        for(int i=0;i<n;i++){
            stocks.push_back({price[i],i+1});
        }
        sort(stocks.begin(),stocks.end());
        int cnt=0;
        for(int i=0;i<n;i++){
            if(k==0) break;
            int stockPrice = stocks[i].first;
            int maxNum = stocks[i].second;
            int val = k-(k % stockPrice);
            int posNum=min(maxNum,(val/stockPrice));
            k-=posNum*stockPrice;
            cnt+=posNum;
        }
        return cnt;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends