class Solution {
private:
    // int mul(long long a, long long b){
    //     int mod = 1000000007;
    //     return ((a % mod) * (b % mod)) % mod; 
    // }

    // Recursion (stack overflow)

    // int helper(long long i){
    //     if(i==0) return 5;
    //     long long a= helper(i-1);
    //     if((i%2)==0) return mul(a,5);
    //     return mul(a,4);
    // }
public:
    int mod = 1000000007;
    long long power(long long base, long long exp) {
        
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) { 
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long oddPower = (n + 1) / 2;
        long long evenPower = n / 2;

        long long power5 = power(5, oddPower);
        long long power4 = power(4, evenPower);

        return (int)((power5 * power4) % mod);
    }
};