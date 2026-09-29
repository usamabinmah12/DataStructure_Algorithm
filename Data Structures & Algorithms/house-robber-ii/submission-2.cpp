class Solution {
public:
    int rob(vector<int>& v) {
        int n = v.size();
        vector<int> ans1(n) , ans2(n , 0);
        for(int i = 0 ; i < n - 1; i++) {
            if(!i) {
                ans1[i] = v[i];
            } 
            else if(i == 1) {
                ans1[i] = max(ans1[i - 1] ,v[i]);
            }
            else {
                ans1[i] = max(ans1[i - 2] + v[i], ans1[i - 1]);
            }
        }
        for(int i = 1 ; i < n; i++) {
            if(i == 1) {
                ans2[i] = v[i];
            }
            // else if(i == 2) {
            //     ans2[i] = max(ans2[i - 1] , v[i]);
            // }
            else {
                ans2[i] = max(ans2[i - 2] + v[i], ans2[i - 1]);
            }
        }
        if(n == 1) return v[0];
        return max(ans1[n - 2] ,ans2[n - 1]);
    }
};
