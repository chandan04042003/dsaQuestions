class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        //Brute

        // vector<int> ans;
        // for(auto x: queries){
        //     int f= x[0];
        //     int s=x[1];
        //     int xo=0;
        //     for(int i=f;i<=s;i++){
        //         xo=xo^arr[i];
        //     }
        //     ans.push_back(xo);
        // }
        // return ans;

        // Optimal prefix XOR

        int n = arr.size();
        vector<int> prefixXOR(n + 1, 0);

        // Build prefix XOR array
        for (int i = 0; i < n; i++) {
            prefixXOR[i + 1] = prefixXOR[i] ^ arr[i];
        }

        vector<int> result;
        // Process each query using prefix XOR
        for (const auto& q : queries) {
            result.push_back(prefixXOR[q[1] + 1] ^ prefixXOR[q[0]]);
        }
        return result;
    }
};