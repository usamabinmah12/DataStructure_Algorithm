class Solution {
    int getSqureSum(int n) {
        int sum = 0;
        while(n > 0) {
            sum += ((n % 10 ) * (n % 10));
            n /= 10;

        }
        return sum;
    }
public:
    bool isHappy(int n) {
        set<int> s;
        while(1) {
             if(n == 1 ) {
                 return true;
            }
            n = getSqureSum(n);
            if(s.find(n) == s.end()) {
                s.insert(n);
            }
            else return false;
        }
       
        return false;
    }
};
