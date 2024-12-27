class Solution {
public:
    long long beautifulSubarrays(vector<int>& a) {
        // 2^k , kth bit will be 1 and rest will be 0 , ex:- 2^3 = 1000.
        // let 33= 100001 and 62= be the numbers 111110 , 2^k for which kth bit is 1 for both the
        // numbers is 2^k <= max(33,62) => 2^5=32.
        // this should continue till all the ones in the numbers become 0 => 
        // n1 xor n2 , if not equal to 0 , consider another subarray element and xor.
        // Hence, question got simplified to no. of subarrays with xor equal to 0

        int n = a.size(); //size of the given array.
        long long xr = 0;
        map<long long, int> mpp; //declaring the map.
        mpp[xr]++; //setting the value of 0.
        long long cnt = 0;

        for (int i = 0; i < n; i++) {
            // prefix XOR till index i:
            xr = xr ^ a[i];

            //By formula: x = xr^k:
            long long x = xr ^ 0;

            // add the occurrence of xr^k
            // to the count:
            cnt += mpp[x];

            // Insert the prefix xor till index i
            // into the map:
            mpp[xr]++;
        }
        return cnt;
    }
};