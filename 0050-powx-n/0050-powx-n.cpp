class Solution {
private:
    double fn(double x, long long n){
        if(n==1) return x;
        if(n==0) return 1;
        double a=myPow(x,n/2);
        if(n%2==0) return (a*a);
        else return (a*a*x);
    }
public:
    double myPow(double x, int n) {
        long long p=n;
        if(n<0) p=-p; // note:- mod(INT_MIN)>mod(INT_MAX) 
        double ans=fn(x,p);
        if(n<0) return (1/ans);
        return ans;
    }
};