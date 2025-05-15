class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        while (n >= 5) {
            n /= 5;// (for every iternation n/5/5=> n/25...)
            cnt += n;
        }
        return cnt;
    }
};