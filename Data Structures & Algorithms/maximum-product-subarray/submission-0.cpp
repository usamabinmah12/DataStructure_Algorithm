class Solution {
public:
    int maxProduct(vector<int>& v) {
        int ans = *max_element(v.begin() , v.end() ) ;
        int curMx = 1, curMn = 1;
        for(int i = 0 ; i < v.size() ; i++) {
            int tmp = curMx * v[i];
            curMx = max({tmp , curMn * v[i] , v[i]});
            curMn = min({tmp , curMn * v[i] , v[i]});
            ans = max(ans , curMx);
        }
        return ans;
    }
};
