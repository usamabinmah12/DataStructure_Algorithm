class Solution {
    double binpow(double a , int b) {
        double ans = 1;
        while(b) {
            if(b& 1) ans = (ans * a);
            a = (a * a);
            b /= 2;
        }
        return ans;
    }
public:
    double myPow(double x, int n) {
        double ans = binpow(x , n);
        if(n <0 ) {
            ans =1.0 / ans;
        }
        return ans;
    }
};
