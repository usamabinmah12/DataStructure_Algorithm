class Solution {
public:
    int maxArea(vector<int>& v) {
        int l = 0 , r = v.size() - 1 , ans =0;
        while(l < r) {
            int cur = (r - l) * min(v[l] , v[r]);
            ans = max(ans , cur);
            if(v[l] < v[r]) ++l;
            else r--;
        }
        return ans;
    }
};
